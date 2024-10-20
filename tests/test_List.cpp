// Copyright 2024 Marina Usova

#include <gtest.h>
#include "../lib_List/List.h"


TEST(TestListLib, push_front_1) {
  TList<int> obj;
  obj.push_back(6);
  obj.push_front(34);
  int actual_result = obj.get_head()->value();
  int expected_result =34;
  int actual_result_2 = obj.get_tail()->value();
  int expected_result_2 = 6;
  EXPECT_EQ(expected_result, actual_result);
  EXPECT_EQ(expected_result_2, actual_result_2);
}


TEST(TestListLib, push_front_2) {
  TList<int> obj;
  obj.push_front(34);
  int actual_result = obj.get_head()->value();
  int expected_result = obj.get_tail()->value();
  EXPECT_EQ(expected_result, actual_result,34);
  
}



TEST(TestListLib, push_back_1) {
  TList<int> obj;
  obj.push_front(34);
  obj.push_back(8);
  int actual_result = obj.get_head()->value();
  int expected_result = 34;
  int actual_result_2 = obj.get_tail()->value();
  int expected_result_2 = 8;
  EXPECT_EQ(expected_result, actual_result);
  EXPECT_EQ(expected_result_2, actual_result_2);
}


TEST(TestListLib, push_back_2) {
  TList<int> obj;
  obj.push_back(8);
  int actual_result = obj.get_head()->value();
  int expected_result = obj.get_tail()->value();
  EXPECT_EQ(expected_result, actual_result,8);
  
}


TEST(TestListLib, get_tail) {
  TList<int> obj;
  obj.push_front(69);
  obj.push_front(309);
  int actual_result = obj.get_tail()->value();
  int expected_result = 69;
  EXPECT_EQ(expected_result, actual_result);
}

TEST(TestListLib, get_head) {
  TList<int> obj;
  obj.push_front(23);
  obj.push_front(39);
  int actual_result = obj.get_head()->value();
  int expected_result = 39;
  EXPECT_EQ(expected_result, actual_result);
}


TEST(TestListLib, insert_by_the_pointer_1) {
  TList<int> obj;
  TNode<int>* node = nullptr;
 
  ASSERT_THROW(obj.insert(node, 2); , std::logic_error);
}

TEST(TestListLib, insert_by_the_pointer_2) {
  TList<int> obj;
  obj.push_front(23);
  obj.push_front(39);
  obj.insert(obj.get_tail(), 2);
  int actual_result = obj.get_tail()->value();
  int expected_result = 2;
  EXPECT_EQ(expected_result, actual_result);
}



TEST(TestListLib, insert_by_position_1) {
  TList<int> obj;
  obj.push_front(23);
  obj.push_front(39);
  obj.insert(2, 82);
  int actual_result = obj.get_tail()->value();
  int expected_result = 82;
  EXPECT_EQ(expected_result, actual_result);
}


TEST(TestListLib, insert_by_the_position_2) {
  TList<int> obj;
  obj.push_front(23);
  obj.push_front(39);

  ASSERT_THROW(obj.insert(7, 2);, std::logic_error);
  ASSERT_THROW(obj.insert(-7, 2); , std::logic_error);

}


TEST(TestListLib, find) {
  TList<int> obj;
  obj.push_front(23);
  obj.push_front(39);
  obj.insert(2, 82);
  
  TNode<int>* actual_result = obj.find(39);
  TNode<int>* expected_result = obj.get_head();
  EXPECT_EQ(expected_result, actual_result);
}

TEST(TestListLib, pop_front_1) {
  TList<int> obj;
  obj.push_front(3);
  obj.push_front(23);
  obj.push_front(39);
  obj.pop_front();
  int actual_result = obj.get_head()->value();
  int expected_result = 23;
  int actual_result_2 = obj.get_tail()->value();
  int expected_result_2 = 3;
  EXPECT_EQ(expected_result, actual_result);
  EXPECT_EQ(expected_result_2, actual_result_2);
}


TEST(TestListLib, pop_front_2) {
  TList<int> obj;
  ASSERT_THROW(obj.pop_front(); , std::logic_error);

}

TEST(TestListLib, pop_back_1) {
  TList<int> obj;
  obj.push_front(3);
  obj.push_front(23);
  obj.push_front(39);
  obj.pop_back();
  int actual_result = obj.get_tail()->value();
  int expected_result = 23;
  int actual_result_2 = obj.get_head()->value();
  int expected_result_2 = 39;
  EXPECT_EQ(expected_result, actual_result);
  EXPECT_EQ(expected_result_2, actual_result_2);
}


TEST(TestListLib, pop_back_2) {
  TList<int> obj;
 
  ASSERT_THROW(obj.pop_back();, std::logic_error);

}

TEST(TestListLib, erase_by_pointer_1) {
  TList<int> obj;
  obj.push_front(39);
  obj.push_front(23);
  obj.push_front(90);
  obj.erase(obj.get_head());
  int actual_result = obj.get_head()->value();
  int expected_result = 23;
  EXPECT_EQ(expected_result, actual_result);
}



TEST(TestListLib, erase_by_pointer_2) {
  TList<int> obj;
  TNode<int>* node = nullptr;
  ASSERT_THROW(obj.erase(node); , std::logic_error);
}



TEST(TestListLib, erase_by_pointer_3) {
  TList<int> obj;
  obj.push_front(39);
  obj.push_front(23);
  obj.push_front(90);
  obj.erase(obj.get_tail());
  int actual_result = obj.get_tail()->value();
  int expected_result = 23;
  EXPECT_EQ(expected_result, actual_result);
}

TEST(TestListLib, erase_by_position_1) {
  TList<int> obj;
  obj.push_front(39);
  obj.push_front(23);
  obj.push_front(90);
  obj.erase(3);
  int actual_result = obj.get_tail()->value();
  int expected_result = 23;
  EXPECT_EQ(expected_result, actual_result);
}


TEST(TestListLib, erase_by_position_2) {
  TList<int> obj;
  obj.push_front(57);
  ASSERT_THROW(obj.erase(5);, std::logic_error);
  ASSERT_THROW(obj.erase(-5); , std::logic_error);
}


TEST(TestListLib, erase_by_position_3) {
  TList<int> obj;
  obj.push_front(39);
  obj.push_front(23);
  obj.push_front(90);
  obj.erase(1);
  int actual_result = obj.get_head()->value();
  int expected_result = 23;
  EXPECT_EQ(expected_result, actual_result);
}


TEST(TestListLib, erase_by_position_4) {
  TList<int> obj;
  obj.push_front(39);
  obj.push_front(23);
  obj.push_front(90);
  obj.erase(3);
  int actual_result = obj.get_tail()->value();
  int expected_result = 23;
  EXPECT_EQ(expected_result, actual_result);
}

TEST(TestListLib, isEmpty) {
  TList<int> obj;
  ASSERT_TRUE(obj.isEmpty());
}


TEST(TestListLib, replace_by_pointer_1) {
  TList<int> obj;
  obj.push_back(39);
  obj.push_back(23);
  obj.push_back(90);
  obj.replace(obj.get_head(),45);
  int actual_result = obj.get_head()->value();
  int expected_result = 45;
  EXPECT_EQ(expected_result, actual_result);
}



TEST(TestListLib, replace_by_pointer_2) {
  TList<int> obj;
  TNode<int>* node = nullptr;
  obj.push_front(57);
  obj.push_back(39);
  obj.push_back(23);
  obj.push_back(90);
  ASSERT_THROW(obj.replace(node, 8);, std::logic_error);
}

TEST(TestListLib, replace_by_position_1) {
  TList<int> obj;
  obj.push_back(39);
  obj.push_back(23);
  obj.push_back(90);
  obj.replace(2, 45);
  TNode<int>* actual_result = obj.find(45);
  obj.pop_back();
  TNode<int>* expected_result = obj.get_tail();
  EXPECT_EQ(expected_result, actual_result);
}


TEST(TestListLib, replace_by_position_2) {
  TList<int> obj;
  obj.push_front(57);
  obj.push_back(39);
  obj.push_back(23);
  obj.push_back(90);
  ASSERT_THROW(obj.replace(6, 8); , std::logic_error);
  ASSERT_THROW(obj.replace(-3, 8);, std::logic_error);
}

TEST(TestListLib, return_size) {
  TList<int> obj;
  obj.push_back(39);
  obj.push_back(23);
  obj.push_back(90);
  obj.pop_front();
  int actual_result = obj.get_size();
  int expected_result = 2;
  EXPECT_EQ(expected_result, actual_result);
}

