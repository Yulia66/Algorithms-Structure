#include <iostream> 
template <class T>
class TNode {
  T _value;
  TNode <T>* _pnext;
public:
  TNode<T>* next();
  TNode(T val, TNode<T>* node = nullptr);
  bool operator==(TNode<T>* node);
  TNode(const TNode<T>& node);
  TNode<T>& operator=(const TNode<T>& node);
  T value();
};
template <typename T>
TNode<T>::TNode(T val, TNode<T>* node) {
  _value = val;
  _pnext = node;
}


template <typename T>
TNode<T>::TNode(const TNode<T>& node) {
  _value = node._value;
  _pnext = node._pnext;
}

template <typename T>
TNode<T>& TNode<T>:: operator=(const TNode<T>& node) {
  _value = node._value;
  return *this;
}


template <typename T>
T TNode<T>::value() {
  return _value;
}

template <typename T>
TNode<T>* TNode<T>::next() {
  return _pnext;
}




template <typename T>
bool TNode<T>:: operator==(TNode<T>* node) {
  return _value == node->value;
}

template <typename T>
class TList : public TNode<T> {
  TNode<T>* head;
  TNode<T>* tail;
  size_t size;
public:
  TList();
  TList(const TList& list);
 // ~TList();
  void push_front(const T& value) noexcept;
  void push_back(const T& value) noexcept;

  void insert(TNode<T>* node, const T& value);
  void insert(size_t pos, const T& value);
  TNode<T>* find(const T& value) const noexcept;
  void pop_front();
  void pop_back();
  void erase(TNode<T>* node);
  void erase(size_t pos);
  bool isEmpty();
  void replace(TNode<T>* node);
  void replace(size_t pos);
  void sort(TList<T> list) noexcept;

};

/*template <typename T>
void TList<T>::erase(size_t pos) {

}
*/


template <typename T>
void TList<T>::erase(TNode<T>* node) {
  TNode<T>* current = head;
  while (current->next != tail) {
    current = current->next;
  }
  TNode<T>* new_node = current->next;
  current->next(new_node->next);
  delete current->next;
}

/*template <typename T>
void TList<T>::insert(size_t pos, const T& value) {

}
*/


template <typename T>
void TList<T>::insert(TNode<T>* node, const T& value) {
  if (node == nullptr) {
    throw std::logic_error;
  }
  TNode<T>* new_node = new TNode<T>(value, node->next());
  node->next(new_node);
  if (node == tail) {
    tail = new_node;
  }
  size++;
}

template <typename T>
void TList<T>::pop_back() {
  TNode<T>* current = head;
  while (current->next != tail) {
    current = current->next;
  }

  delete tail;
  tail = current;
  tail->next = nullptr;

}



/*template <typename T>
TList<T>:: ~TList(){
  delete[] 
}*/
template <typename T>
TList<T>::TList() {
  head = nullptr;
  tail = nullptr;
}


template <typename T>
void TList<T>::pop_front() {
  TNode<T>* new_head = head;
  new_head = new_head->next(head);
  head = new_head;
  delete new_head;
}



template <typename T>
TList<T>::TList(const TList& list) {
  head = nullptr;
  tail = nullptr;
  TNode<T>* current = list.head;
  while (current != nullptr) {
    push_back(current->value);
    current->next(current);
  }
}

/*template <typename T>
TNode<T>* TList<T>::find(const T& value) const noexcept {

}
*/



template <typename T>
void TList<T>::push_front(const T& value) noexcept {
  TNode<T>* new_node = new TNode<T>(value);
  if (isEmpty()) {
    head = new_node;
    tail = new_node;
  }
  else {
    new_node->next(head);
    head = new_node;
  }
  size++;
}

template <typename T>
void TList<T>::push_back(const T& value) noexcept {
  TNode<T>* new_node = new TNode<T>(value);
  TNode<T>* old_tail = tail;
  if (isEmpty()) {
    head = new_node;
    tail = new_node;
  }
  else {
    old_tail->next(new_node);
    tail = new_node;
  }
  size++;
}

/*template <typename T>
TNode<T>* cur{
cur = head;
while(cur != cur->next(nullptr) {

}
}*/