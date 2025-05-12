#include <gtest.h>
#include "../lib_Queue/Queue.h"
/*

TEST(QueueLib,initialization_constructor) {
  Queue<int> obj;
  
  ASSERT_EQ(obj.Front(), -1);
  ASSERT_EQ(obj.Ends(), -1);
}


TEST(QueueLib, return_Front) {
  Queue<int > obj;
  obj.add_element(2);

  int actual_result = obj.Front();


  int expected_result = 0;
  EXPECT_EQ(expected_result, actual_result);
}

TEST(QueueLib, return_Ends) {
  Queue<int > obj;
  obj.add_element(2);

  int actual_result = obj.Ends();


  int expected_result = 0;
  EXPECT_EQ(expected_result, actual_result);
}


TEST(QueueLib, isEmpty_1) {
  Queue<int> obj;
  ASSERT_TRUE(obj.isEmpty());
}


TEST(QueueLib, isEmpty_2) {
  Queue<int> obj;
  obj.add_element(2);
  ASSERT_FALSE(obj.isEmpty());
}


TEST(QueueLib, isFull_1) {
  Queue<int> obj;
  obj.add_element(2);
  obj.add_element(2);
  obj.add_element(2);
  obj.add_element(2);
 obj.add_element(2);
  ASSERT_TRUE(obj.isFull());
}
TEST(QueueLib, isFull_2) {
  Queue<int> obj;
  obj.add_element(2);
  obj.add_element(2);
  ASSERT_FALSE(obj.isFull());
}




TEST(QueueLib, Add_elements_1) {

  Queue<int> obj;
  obj.add_element(87);
  obj.add_element(23);
  obj.add_element(6);
  int actual_result = obj.Items()[obj.Front()];
  int expected_result = 87;
  EXPECT_EQ(expected_result, actual_result);
}

TEST(QueueLib, Add_elements_2) {

  Queue<int> obj;
  obj.add_element(87);
  obj.add_element(23);
  obj.add_element(6);
  obj.add_element(23);
  obj.add_element(6);
  ASSERT_THROW(obj.add_element(23), std::logic_error);
}

TEST(QueueLib, Add_elements_3) {

  Queue<int> obj;
  obj.add_element(87);
  int actual_result = obj.Front();
  int expected_result = 0;
  EXPECT_EQ(expected_result, actual_result);
}


TEST(QueueLib, Detete_elements_1) {

  Queue<int> obj;
  ASSERT_THROW(obj.delete_element(), std::logic_error);
}

TEST(QueueLib, Delete_elements_2) {

  Queue<int> obj;
  obj.add_element(87);
  obj.delete_element();

  int actual_result = obj.Front();
  int expected_result = -1;
  EXPECT_EQ(expected_result, actual_result);
}


TEST(QueueLib, Delete_elements_3) {

  Queue<int> obj;
  obj.add_element(87);
  obj.add_element(6);
  obj.add_element(23);
  obj.delete_element();

  int actual_result = obj.Items()[obj.Front()];
  int expected_result = 6;
  EXPECT_EQ(expected_result, actual_result);
}
*/
/*

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



TEST(StackLib, size) {
  Stack<int> obj;
  obj.push(1)(2);;
  obj.push
  obj.push(3);
  int actual_result = obj.size();
  int expected_result = 3;
  EXPECT_EQ(expected_result, actual_result);
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
}*/