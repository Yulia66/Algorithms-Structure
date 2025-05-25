#include <iostream>

template <class T>
class BTreeNode {

    T _value;

    BTreeNode<T>* left, * right;
    bool status = false;

public:
    BTreeNode();
    ~BTreeNode() { clear(); }
    BTreeNode(T val);
    BTreeNode<T>* search(BTreeNode<T>* root, T val);
    BTreeNode<T>* insert(BTreeNode<T>* root, T val);
    BTreeNode<T>* erase(BTreeNode<T>* root, T val);
    void clear();
    void print(BTreeNode<T>* root);
    BTreeNode<T>* Min(BTreeNode<T>* root);
    BTreeNode<T>* createNode(T data);


    T getValue() const { return _value; }
    BTreeNode<T>* getLeft() const { return left; }
    BTreeNode<T>* getRight() const { return right; }
    bool getStatus() const { return status; }
};



template <typename T>
BTreeNode<T>::BTreeNode() {
    left = nullptr;
    right = nullptr;
}


template <typename T>
BTreeNode<T>::BTreeNode(T val) {
    _value = val;
    left = nullptr;
    right = nullptr;
}

template <typename T>
void BTreeNode<T>::clear() {
    if (left != nullptr) {
        left->clear();
        delete left;
        left = nullptr;
    }
    if (right != nullptr) {
        right->clear();
        delete right;
        right = nullptr;
    }
    status = false;
}

template <typename T>
BTreeNode<T>* BTreeNode<T>::createNode(T data)
{
    BTreeNode<T>* newNode = new BTreeNode<T>();
    newNode->_value = data;
    newNode->left = newNode->right = nullptr;

    return newNode;
}


template <typename T>
BTreeNode<T>* BTreeNode<T>::search(BTreeNode<T>* root, T val) {

    if (root == nullptr || root->_value == val) {
        return root;
    }
    if (val < root->_value) {

        return search(root->left, val);
    }

    return search(root->right, val);

}



template <typename T>
BTreeNode<T>* BTreeNode<T>::erase(BTreeNode<T>* result, T val) {

    if (result == nullptr) {
        return nullptr;
    }
    if (val < result->_value) {
        result->left = erase(result->left, val);
    }
    else if (val > result->_value) {
        result->right = erase(result->right, val);
    }
    else {
        if (result->left == nullptr) {
            BTreeNode<T>* temp = result->right;
            delete result;
            return temp;
        }
        if (result->right == nullptr) {
            BTreeNode<T>* temp = result->left;
            delete result;
            return temp;
        }
        else {
            BTreeNode<T>* temp_2 = Min(result->right);
            result->_value = temp_2->_value;
            result->right = erase(result->right, temp_2->_value);
        }
    }
    return result;
}


template <typename T>
BTreeNode<T>* BTreeNode<T>::Min(BTreeNode<T>* root) {
    BTreeNode<T>* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}
template <typename T>
BTreeNode<T>* BTreeNode<T>::insert(BTreeNode<T>* result, T val) {
    if (result == nullptr) {
        return createNode(val);

    }
    if (val < result->_value) {
        result->left = insert(result->left, val);
    }
    if (val > result->_value) {
        result->right = insert(result->right, val);
    }
    status = true;
    return result;
}
template <typename T>
void BTreeNode<T>::print(BTreeNode<T>* root) {
    if (status== false) {
        throw std::logic_error("Tree is empty");
    }
    if (root != nullptr) {
        print(root->left);
        std::cout << root->_value << " ";
        print(root->right);
    }


}
