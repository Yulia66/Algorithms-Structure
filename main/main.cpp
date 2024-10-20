// Copyright 2024 Marina Usova

#define LIST
#ifdef EASY_EXAMPLE

#include <iostream>
#include <iomanip>
#include "../lib_easy_example/easy_example.h"

int main() {
  int a, b;
  float result;

  a = 1; b = 4;

  try {
      result = division(a, b);
      std::cout << a << " / " << b << " = "
          << std::setprecision(2) << result << std::endl;
  } catch (std::exception err) {
      std::cerr << err.what() << std::endl;
  }

  a = 1; b = 0;

  try {
      result = division(a, b);
      std::cout << a << " / " << b << " = "
          << std::setprecision(2) << result << std::endl;
  } catch (std::exception err) {
      std::cerr << err.what() << std::endl;
  }

  return 0;
}

#endif  // EASY_EXAMPLE


#ifdef LIST
#include <iostream>
#include <iomanip>
#include "../lib_List/List.h"


int main() {
  TList<int> list;
  TNode<int>* node = new TNode<int>(101);


  //list.push_front(10); 
  list.push_front(12);
  list.push_front(13);
  try {
    list.insert(2, 24);
  }
  catch (const std::logic_error& error) {

    std::cerr << "Error in void insert(size_t pos, const T& value): " << error.what() << std::endl;

  }
  try {
    list.erase(list.get_tail());
  }
  catch (const std::logic_error& error) {

    std::cerr << "Error in void erase(size_t pos): " << error.what() << std::endl;
  }
  std::cout << list.get_tail()->value();
 /* 
  list.push_back(9);
  list.push_back(9);
  list.push_back(92);
  

  try {
    list.insert(list.get_head(), 2);
  }
  catch (const std::logic_error& error) {

    std::cerr << "Error in void insert(TNode<T>* node, const T& value): " << error.what() << std::endl;

  }*/
  /*



  try {
    list.replace(list.get_tail(), 67);
  }
  catch (const std::logic_error& error) {

    std::cerr << "Error in void replace(TNode<T>* current, T val): " << error.what() << std::endl;


  }
  try {
    list.replace(1, 6);
  }
  catch (const std::logic_error& error) {

    std::cerr << "Error in void replace(size_t pos, T val): " << error.what() << std::endl;

  }
  //list.replace(2, 78);
  try {
    list.erase(list.get_tail());
  }
  catch (const std::logic_error& error) {

    std::cerr << "Error in void erase(TNode<T>* node): " << error.what() << std::endl;
  }
  
  //list.erase(list.get_head());
  //list.pop_front();
  //list.pop_back();
 
  //list.pop_front(); 
  try {
    list.pop_back();
  }catch (const std::logic_error& error) {

    std::cerr << "Error in void pop_back(): " << error.what() << std::endl;
  }*/
  list.print();
  //std::cout<< list.get_tail()->_value; 
  //std::cout << list.get_size(); 
  return 0;
}


#endif  // LIST
