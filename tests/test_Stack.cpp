#include <gtest.h>
#include "../lib_Stack/Stack_.h"


TEST(StackLib,initialization_constructor) {
  Stack<int> obj;
  
  ASSERT_EQ(obj.get_capacity(), 5);
}




TEST(StackLib, push) {
  
  int count = 3;
  Stack<int> obj;
  obj.push(count);
  
  int actual_result = obj.peek();

 
  int expected_result = 3;
  EXPECT_EQ(expected_result, actual_result);
}



TEST(StackLib, pop) {
 
  Stack<int> obj;
  obj.push(2);
  obj.push(23);
  obj.pop();
   
  int actual_result = obj.peek();
  int expected_result = 2;
  
 
  EXPECT_EQ(expected_result, actual_result);
}



TEST(StackLib, peek) {

  int count = 3;
  Stack<int> obj;
  obj.push(count);
  int actual_result = obj.peek();
  int expected_result = 3;
  EXPECT_EQ(expected_result, actual_result);
}


TEST(StackLib, get_capacity) {
  Stack<int> obj;
  int actual_result = obj.get_capacity();
  int expected_result = 5;
  EXPECT_EQ(expected_result, actual_result);
}


/*
TEST(StackLib, size) {
  Stack<int> obj;
  obj.push(1)(2);;
  obj.push
  obj.push(3);
  int actual_result = obj.size();
  int expected_result = 3;
  EXPECT_EQ(expected_result, actual_result);
}
*/


TEST(StackLib, isEmpty) {
  Stack<int> obj;
  ASSERT_TRUE(obj.isEmpty());
}


TEST(StackLib, isFull) {
  Stack<int> obj;
  ASSERT_FALSE(obj.isFull());
}


TEST(StackLib, push_is_Full) {
  Stack<int> obj;
  obj.push(1);
  obj.push(2);
  obj.push(3);
  obj.push(4);
  obj.push(5);
  ASSERT_THROW(obj.push(6), std::logic_error);
}

TEST(StackLib, pop_is_Empty) {
  Stack<int> obj;

  ASSERT_THROW(obj.pop(), std::logic_error);
}