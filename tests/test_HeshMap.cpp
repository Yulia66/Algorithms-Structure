#include <gtest.h>
#include "../lib_HeshMap/HeshMap.h"



TEST(HeshMap, Hesh_function_string) {
	Hesh_table<std::string,int> obj;
	int res = obj.insert("pol", 55);
	ASSERT_EQ(res, 13);
}
/*
TEST(HeshMap, Hesh_function_throw) {
	Hesh_table<char, int> obj;
	ASSERT_THROW(obj.insert('l', 55), std::logic_error);

}
*/

TEST(HeshMap, Hesh_function_int) {
	Hesh_table<int, int> obj;
	int res = obj.insert(65, 55);
	ASSERT_EQ(res, 10);
}



/*

// Тесты
TEST(StackLib, initialization_constructor) {
  Stack<int> obj;

  ASSERT_EQ(obj.get_capacity(), 5);
  ASSERT_TRUE(obj.isEmpty());
}

TEST(StackLib, push_and_pop) {
  Stack<int> obj;

  obj.push(10);
  ASSERT_EQ(obj.size(), 1);
  ASSERT_FALSE(obj.isEmpty());
  ASSERT_EQ(obj.peek(), 10);

  obj.push(20);
  ASSERT_EQ(obj.size(), 2);
  ASSERT_EQ(obj.peek(), 20);

  ASSERT_EQ(obj.pop(), 20);
  ASSERT_EQ(obj.size(), 1);
}

TEST(StackLib, overflow) {
  Stack<int> obj(2); 

  obj.push(10);
  obj.push(20);

  ASSERT_THROW(obj.push(30), std::logic_error); // Ожидаем исключение
}

TEST(StackLib, underflow) {
  Stack<int> obj;

  ASSERT_THROW(obj.pop(), std::logic_error); // Ожидаем исключение
}

TEST(StackLib, peek_on_empty_stack) {
  Stack<int> obj;

  ASSERT_THROW(obj.peek(), std::logic_error); // Ожидаем исключение
}
*/