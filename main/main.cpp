#define POLYNOM


#ifdef POLYNOM
#include <iostream>   
#include <vector>
#include <windows.h>
#include <cmath>
#include <list>
#include "../lib_Polynom/Polynom.h"
int main() {
  // SetConsoleOutputCP(CP_UTF8);
  Polynom pol("2x^4y^5z^748+2z^5+9y^5z^23");
  Monom* my = new Monom();
  //std::cin >> my->_coef>>my->d_x >>  my->d_y >>  my->d_z;
  Monom monom(1, 1, 0, 0);
  Monom monom_copy(9, 0, 0, 0);
  Monom m;
  m = (monom / monom_copy);
  // (*my).print();
  pol.add_monom(monom);
  pol.print();
  return 0;
}
#endif


#ifdef ITERATOR
#include <iostream>
#include "../lib_Iterator/Iterator.h"
int main() {
  TList<int> myList;
  myList.push_back(1);
  myList.push_back(2);
  myList.push_back(3);
  //myList.print();
  for (TList<int>::Iterator it = myList.begin(); it != myList.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  return 0;
}
#endif

#ifdef STACKONLIST


#include <iostream>
#include "../lib_StackOnList/StackOnList.h"

int main() {
  StackOnList<int> list;
  list.push(3);
  list.push(36);
  list.push(30);
  list.pop();
  list.pop();
 //list.pop();
  try {
    std::cout << list.top();
    
  }
  catch (const std::logic_error& error) {

    std::cerr << error.what() << std::endl;

  }

  return 0;
}
#endif

#ifdef QUEUE
#include "../lib_Queue/Queue.h"
#include <iostream>
int main() {
  Queue<int> obj;

  obj.delete_element();

  obj.add_element(1);
  obj.add_element(2);
  obj.add_element(3);
  obj.add_element(4);
  obj.add_element(5);

  obj.add_element(6);

  obj.print();

  obj.delete_element();

  obj.print();

  return 0;
}
#endif

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
  std::cout << list.find(155)->value();
  //std::cout<< list.get_tail()->_value; 
  //std::cout << list.get_size(); 
  return 0;
}


#endif  // LIST



#ifdef DMASSIVE
#include <iostream>
#include "../lib_DMassive/archive.h"
#include "../lib_DMassive/utilities.h"

enum Actions { EXIT, INSERT, FIND, REMOVE, CLEAN };

int main() {
  TArchive<int> archive;
  size_t n, pos;
  int* values = nullptr;
  int user;

  std::exception err;
  bool exit = false;
  bool success;
  InputSystem::InsertMode mode;
  InputSystem::InsertMode_Remove mode_2;
  while (!exit) {
    system("cls");
    OutputSystem::show(archive);
    std::cout << "Menu:\n 1. insert,\n 2. find,\n 3. delete,\n 4. clean,\n 0. exit.\nYour choose: ";
    std::cin >> user;



    switch (user) {
    case Actions::EXIT:
      exit = true;
      break;






    case Actions::INSERT://                    ÂÑÒÀÂÊÀ
      if (values != nullptr) { delete[] values; values = nullptr; }
      values = InputSystem::insert<int>(n, pos, mode);
      success = false;
      if (mode == InputSystem::InsertMode::OneValue) {
        try {
          archive.insert(values[0], pos);
          success = true;
        }
        catch (std::exception err) {
          std::cerr << err.what() << std::endl;
        }

      }

      if (mode == InputSystem::InsertMode::SeveralValues) {
        try {
          archive.insert(values, n, pos);
          success = true;
        }
        catch (std::exception err) {
          std::cerr << err.what() << std::endl;
        }
      }

      if (mode == InputSystem::InsertMode::Front) {
        try {
          archive.push_front(values[0]);
          success = true;
        }
        catch (std::exception err) {
          std::cerr << err.what() << std::endl;
        }
      }
      if (mode == InputSystem::InsertMode::Back) {
        try {
          archive.push_back(values[0]);
          success = true;
        }
        catch (std::exception err) {
          std::cerr << err.what() << std::endl;
        }
      }
      if (success) {
        OutputSystem::insert();
      }
      system("pause");
      break;












    case Actions::FIND://                          ÏÎÈÑÊ
      std::cout << "TBD" << std::endl;
      system("pause");
      break;









    case Actions::REMOVE://                        ÓÄÀËÅÍÈÅ
      if (values != nullptr) { delete[] values; values = nullptr; }
      values = InputSystem::remove<int>(n, pos, mode, mode_2);
      if (mode == InputSystem::InsertMode::Front && mode_2 == InputSystem::InsertMode_Remove::Position) {
        try {
          archive.pop_front();
        }
        catch (std::exception err) {
          std::cerr << err.what() << std::endl;
        }
      }

      if (mode == InputSystem::InsertMode::Back && mode_2 == InputSystem::InsertMode_Remove::Position) {
        try {
          archive.pop_back();
        }
        catch (std::exception err) {
          std::cerr << err.what() << std::endl;
        }
      }
      if (mode == InputSystem::InsertMode::OneValue && mode_2 == InputSystem::InsertMode_Remove::Position) {
        try {
          archive.remove_by_index(pos);
        }
        catch (std::exception err) {
          std::cerr << err.what() << std::endl;
        }
      }
      if (mode == InputSystem::InsertMode::SeveralValues && mode_2 == InputSystem::InsertMode_Remove::Position) {
        try {
          archive.erase(pos, n);
        }
        catch (std::exception err) {
          std::cerr << err.what() << std::endl;
        }
      }
      if (mode == InputSystem::InsertMode::Back && mode_2 == InputSystem::InsertMode_Remove::Value) {

        archive.remove_last(values[0]);

      }
      if (mode == InputSystem::InsertMode::Front && mode_2 == InputSystem::InsertMode_Remove::Value) {

        archive.remove_first(values[0]);

      }
      if (mode == InputSystem::InsertMode::All && mode_2 == InputSystem::InsertMode_Remove::Value) {

        archive.remove_all(values[0]);

      }
      system("pause");
      break;





    case Actions::CLEAN:
      archive.clear();
      break;
    }
  }

  return 0;
}




#endif