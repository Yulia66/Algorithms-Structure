#include <iostream>
#define SIZE 5

using namespace std;
template<typename T>
class Queue {
private:
  int items[SIZE], front, ends;

public:
  Queue() {
    front = -1;
    ends = -1;
  }

  int* Items() {
    return items;
  }
 
  int Front() {
    return front;
  }

  int Ends() {
    return ends;
  }
 

  bool isFull() {
    if (front == 0 && ends == SIZE - 1) {
      return true;
    }
    return false;
  }

  bool isEmpty() {
    if (front == -1)
      return true;
    else
      return false;
  }

  void add_element(int element) {
    if (isFull()) {
      throw std::logic_error("The queue is full!!!\n");
    }
    else {
      if (front == -1) front = 0;
      ends++;
      items[ends] = element;
    }
  }

  void delete_element() {
    int element;
    if (isEmpty()) {
      throw std::logic_error("The queue is empty!!!\n");

    }
    else {
      element = items[front];
      if (front >= ends) {
        front = -1;
        ends = -1;
      } 
      else {
        front++;
      }

    }
  }

  void print() {
    int i;
    if (isEmpty()) {
      cout << endl
        << "The queue is empty " << endl;
    }
    else {
        cout<< "Element -> ";
        for (i = front; i <= ends; i++) {
          cout << items[i] << "  ";
        }
        cout << endl;
    }
  }
};
