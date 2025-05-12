#include <gtest.h>
#include "../lib_mas_sorted/mas_sorted.h"



TEST(sortedTableTest, InsertWithGeneratedKey) {
    sorted<int, std::string> table;
    int key = table.insert("Value1");
    EXPECT_TRUE(key >= 1 && key <= 100); 
    EXPECT_EQ(table.find(key).second, "Value1");
}


TEST(sortedTableTest, InsertWithSpecifiedKey) {
    sorted<int, std::string> table;
    table.insert(1, "Value1");
    EXPECT_EQ(table.find(1).second, "Value1"); 
}



TEST(sortedTableTest, RemoveElement) {
    sorted<int, std::string> table;
    table.insert(1, "Value1");
    table.remove(1);
    EXPECT_THROW(table.find(1), std::logic_error); 
}



TEST(sortedTableTest, FindElement) {
    sorted<int, std::string> table;
    table.insert(1, "Value1");
    EXPECT_EQ(table.find(1).second, "Value1");
}

TEST(sortedTableTest, FindNonExistentElement) {
    sorted<int, std::string> table;
    EXPECT_THROW(table.find(1), std::logic_error); 
}


TEST(sortedTableTest, InsertDuplicateKey) {
    sorted<int, std::string> table;
    table.insert(1, "Value1");
    EXPECT_THROW(table.insert(1, "Value2"), std::logic_error); 
}

TEST(sortedTableTest, RemoveNonExistentElement) {
    sorted<int, std::string> table;
    EXPECT_THROW(table.remove(1), std::logic_error); 
}
