#include <iostream> 
#include <cstdlib> 
using namespace std;

template <class T>
class Stack
{

  T* arr;
  int top;
  int capacity;

public:
  Stack(int size = 5);
  ~Stack();

  void push(T);
  int pop();
  int peek();
  T get_capacity();
  int size();
  bool isEmpty();
  bool isFull();
};

template <class T>
T Stack<T>::get_capacity() {
  return capacity;
}

template <class T>
Stack<T>::Stack(int size)
{
  arr = new T[size];
  capacity = size;
  top = -1;
}

template <class T>
Stack<T>::~Stack() {
  delete[] arr;
}

template <class T>
void Stack<T>::push(T x)
{
  if (isFull())
  {
    throw std::logic_error("Overflow\nProgram Terminated\n");

  }
  arr[++top] = x;
}


template <class T>
int Stack<T>::pop()
{

  if (isEmpty())
  {
    throw std::logic_error("Underflow\nProgram Terminated\n");

  }


  return arr[top--];
}

template <class T>
int Stack<T>::peek()
{
  if (!isEmpty()) {
    return arr[top];
  }
  else {
    exit(EXIT_FAILURE);
  }
}

template <class T>
int Stack<T>::size() {
  return top + 1;
}

template <class T>
bool Stack<T>::isEmpty() {
  return top == -1;
}

template <class T>
bool Stack<T>::isFull() {
  return top == capacity - 1;
}

