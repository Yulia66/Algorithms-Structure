#include <iostream> 
#include <cstdlib> 
using namespace std;


#define SIZE 10 

 class Stack
{
  int* arr;
  int top;
  int capacity;

public:
  Stack(int size = 10);   
  ~Stack();       

  void push(int);
  int pop();
  int peek();

  int size();
  bool isEmpty();
  bool isFull();
};


Stack::Stack(int size)
{
  arr = new int[size];
  capacity = size;
  top = -1;
}


Stack::~Stack() {
  delete[] arr;
}


void Stack::push(int x)
{
  if (isFull())
  {
    throw std:: logic_error("Overflow\nProgram Terminated\n");
   
  }

  cout << "Input " << x << endl;
  arr[++top] = x;
}



int Stack::pop()
{
  
  if (isEmpty())
  {
    throw std::logic_error("Underflow\nProgram Terminated\n");

  }

  cout << "Removing " << peek() << endl;

  
  return arr[top--];
}


int Stack::peek()
{
  if (!isEmpty()) {
    return arr[top];
  }
  else {
    exit(EXIT_FAILURE);
  }
}


int Stack::size() {
  return top + 1;
}


bool Stack::isEmpty() {
  return top == -1;      
}


bool Stack::isFull() {
  return top == capacity - 1;  
}

