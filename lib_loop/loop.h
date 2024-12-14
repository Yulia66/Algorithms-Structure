#include <iostream>   
#include "../lib_List/List.h"

 
template<typename T>
bool hasCycle(TNode<T>* head) {
  if (head == nullptr) return false;

  TNode* slow = head;
  TNode* fast = head;

  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
      return true;
    }
  }
  return false; 
}
