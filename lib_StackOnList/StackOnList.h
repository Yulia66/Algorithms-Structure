#include <iostream>
#include "../lib_List/List.h"


template <class T>
class StackOnList {

  TList<T> data;


public:
 
  ~StackOnList();

  void push(T);
  void pop();
  T top();
  //T get_capacity();
  int size();
  bool isEmpty();
 // bool isFull();
};


template <class T>
StackOnList<T>::~StackOnList() {
 
}


template <class T>
T StackOnList<T>::top() 
{
  if (isEmpty())
  {
    throw std::logic_error("Underflow\nProgram Terminated\n");

  }
  return data.get_head()->value();
}


template <class T>
void StackOnList<T>::push(T x)
{
 
  data.push_front(x);
  
}

template <class T>
void StackOnList<T>::pop()
{

  if (isEmpty())
  {
    throw std::logic_error("Underflow\nProgram Terminated\n");

  }
  data.pop_front();

 
}

 
template <class T>
int StackOnList<T>::size() {
  return data.get_size();
}

template <class T>
bool StackOnList<T>::isEmpty() {
  return data.isEmpty();
}

