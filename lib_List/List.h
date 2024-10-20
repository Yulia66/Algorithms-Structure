#include <iostream>   
#include <vector> 
template <class T>
class TNode {
public:
  T _value;
  TNode <T>* _next;
 
  TNode<T>();
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
  _next = node;
}

template <typename T>
TNode<T>::TNode<T>() {
  _value = 0;
  _next = nullptr;
}

template <typename T>
TNode<T>::TNode(const TNode<T>& node) {
  _value = node._value;
  _next = node._next;
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
  return _next;
}




template <typename T>
bool TNode<T>:: operator==(TNode<T>* node) {
  return _value == node->value;
}

template <typename T>
class TList : public TNode<T> {
public:
  TNode<T>* head;
  TNode<T>* tail;
  size_t size;

  TList();
  TList(const TList& list);
  // ~TList();  
  void push_front(const T& value) noexcept;//1
  void push_back(const T& value) noexcept;//2
  TNode<T>* get_tail();//3
  TNode<T>* get_head();//4
  void insert(TNode<T>* node, const T& value);//5
  void insert(size_t pos, const T& value);//6
  TNode<T>* find(const T& value) const noexcept;//7
  void pop_front();//8
  void pop_back();//9
  void erase(TNode<T>* node);//10
  void erase(size_t pos);//11
  bool isEmpty();//12
  void replace(TNode<T>* current, T val);//13
  void replace(size_t pos, T val);//14
  void print();
  T get_size();
};

template <typename T>
TList<T>::TList() {
  head = nullptr;
  tail = nullptr;
  size = 0;
}





template <typename T>
TList<T>::TList(const TList& list) {
  size = list.size;
  head = nullptr;
  tail = nullptr;
  TNode<T>* current = list.head;
  while (current != nullptr) {
    push_back(current->value);
    current->_next(current);
  }
}

template <typename T>
void TList<T>::replace(size_t pos, T val) {
  if (pos > size || pos <= 0) {
    throw std::logic_error("unccorect position!!! ");
  }
  if (!isEmpty()) {
    TNode<T>* current = head;
    for (int i = 1; i < size + 1; i++) {
      if (i == pos) {
        break;
      }
      current = current->_next;
    }
    current->_value = val;
  }
}

template <typename T>
TNode<T>* TList<T>::get_tail() {
  return tail;
}


template <typename T>
TNode<T>* TList<T>::get_head() {
  return head;
}



template <typename T>
void TList<T>::replace(TNode<T>* node, T val) {
  if (node == nullptr) {
    throw std::logic_error("null pointer!!!");
  }
  node->_value = val;

}




template <typename T>
void TList<T>::erase(size_t pos) {
  if (pos > size || pos <= 0) {
    throw std::logic_error("unccorect position!!! ");
  }
  if (!isEmpty()) {
    if (pos == 1) {
      pop_front();
      return void();
    }
    if (pos == size) {
      pop_back();
      return void();
    }
    TNode<T>* current = head;
    for (int i = 1; i < pos - 1; i++) {
      current = current->_next;
    }
    TNode<T>* to_delete = current->_next;
    current->_next = to_delete->_next;

    delete to_delete;
  }
}


template <typename T>
void TList<T>::erase(TNode<T>* node) {

  if (node == nullptr) {
    throw std::logic_error("null pointer!!!");
  }
  if (!isEmpty()) {
    if (node == head) {
      pop_front();
      return void();
    }
    if (node == tail) {
      pop_back();
      return void();
    }

    TNode<T>* current = head;
    while (current != nullptr && current->_next != node) {
      current = current->_next;
    }
    if (current == nullptr) {
      throw std::logic_error("Node not found in the list!");
    }
    TNode<T>* new_node = current->_next;
    current->_next = new_node->_next;
    delete new_node;

    size--;
  }
}

template <typename T>
void TList<T>::insert(size_t pos, const T& value) {
  if (pos > size || pos <= 0) {
    throw std::logic_error("unccorect position!!! ");
  }
    TNode<T>* current = head;
    for (int i = 1; i != pos; i++) {
      current = current->_next;
    }
    TNode<T>* new_node = new TNode<T>(value, current->next());
    current->_next = new_node;
    if (new_node->_next==nullptr) {
      tail = new_node;
  }
    size++;
}


template <typename T>
void TList<T>::insert(TNode<T>* node, const T& value) {
  if (node == nullptr) {
    throw std::logic_error("null pointer!!!");
  }
 
    TNode<T>* new_node = new TNode<T>(value, node->next());
    node->_next = new_node;
    if (node == tail) {
      tail = new_node;
    }
    size++;
  }



template <typename T>
void TList<T>::print() {
  TNode<T>* current = head; // Предполагая, что head - это указатель на первый узел списка 
  while (current != nullptr) {
    std::cout << current->_value << ' '; // Выводим значение узла 
    current = current->next(); // Переходим к следующему узлу 
  }
  std::cout << std::endl; // Добавляем перевод строки после печати всех узлов 
}

template <typename T>
bool  TList<T>::isEmpty() {
  return size == 0;
}

template <typename T>
void TList<T>::pop_back() {
  if (tail == nullptr) {
    throw std::logic_error("the list is empty");
  }
 
    TNode<T>* current = head;
    while (current->_next != tail) {
      current = current->_next;
    }

    delete tail;
    tail = current;
    tail->_next = nullptr;
    size--;
  
}




template <typename T>
void TList<T>::pop_front() {
  if (head == nullptr) {
    throw std::logic_error("the list is empty");
  }

  TNode<T>* new_head = head->_next;
  delete head;
  head = new_head;

  size--;
}




template <typename T>
TNode<T>* TList<T>::find(const T& value) const noexcept {
  TNode<T>* current = head;
  for (int i = 1; i < size; i++) {
    if (current->_value == value) {
      return current;
    }
    current = current->_next;
  }
  return 0;
}

template <typename T>
void TList<T>::push_front(const T& value) noexcept {
  TNode<T>* new_node = new TNode<T>(value);
  if (isEmpty()) {
    head = new_node;
    tail = new_node;
  }
  else {
    new_node->_next = head; // Используйте знак равенства для присваивания  
    head = new_node;
  }
  size++;
}


template <typename T>
T TList<T>::get_size() {
  return size;
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
    old_tail->_next = new_node;
    tail = new_node;
  }
  size++;
}