#include <gtest.h>
#include "../lib_list_unsorted/List_unsorted.h"

TEST(listUnsortedTableTest, InsertWithGeneratedKey) {
    sorted<int, std::string> table;
    int key = table.insert("Value1");
    EXPECT_TRUE(key >= 1 && key <= 100); 
    EXPECT_EQ(table.find(key).second, "Value1"); 
}

TEST(listUnsortedTableTest, InsertWithSpecifiedKey) {
    sorted<int, std::string> table;
    table.insert(1, "Value1");
    EXPECT_EQ(table.find(1).second, "Value1"); 
}

TEST(listUnsortedTableTest, RemoveElement) {
    sorted<int, std::string> table;
    table.insert(1, "Value1");
    table.remove(1);
    EXPECT_THROW(table.remove(1), std::logic_error); 
}

TEST(listUnsortedTableTest, FindElement) {
    sorted<int, std::string> table;
    table.insert(1, "Value1");
    EXPECT_EQ(table.find(1).second, "Value1");  
}

 
TEST(listUnsortedTableTest, FindNonExistentElement) {
    sorted<int, std::string> table;
    EXPECT_THROW(table.find(1), std::logic_error); 
}
TEST(listUnsortedTableTest, FindDeletedElement) {
    sorted<int, std::string> table;
    table.insert(1, "Value1");
    table.remove(1);
    EXPECT_THROW(table.find(1), std::logic_error);
}

TEST(listUnsortedTableTest, InsertDuplicateKey) {
    sorted<int, std::string> table;
    table.insert(1, "Value1");
    EXPECT_THROW(table.insert(1, "Value2"), std::logic_error); 
}

TEST(listUnsortedTableTest, RemoveNonExistentElement) {
    sorted<int, std::string> table;
    EXPECT_THROW(table.remove(1), std::logic_error); 
}

TEST(listUnsortedTableTest, GetSize) {
    sorted<int, std::string> table;
    table.insert(1, "Value1");
    table.insert(2, "Value2");
    EXPECT_EQ(table.get_size(), 2); 
}


TEST(listUnsortedTableTest, PrintTable) {
    sorted<int, std::string> table;
    table.insert(1, "Value1");
    table.insert(2, "Value2");
    testing::internal::CaptureStdout(); 
    table.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Key: 1 Value: Value1") != std::string::npos);
    EXPECT_TRUE(output.find("Key: 2 Value: Value2") != std::string::npos);
}

 
TEST(listUnsortedTableTest, CopyConstructor) {
    sorted<int, std::string> table1;
    table1.insert(1, "Value1");
    table1.insert(2, "Value2");

    sorted<int, std::string> table2(table1);
    EXPECT_EQ(table2.find(1).second, "Value1");
    EXPECT_EQ(table2.find(2).second, "Value2");
}


TEST(listUnsortedTableTest, ConstructorWithData) {
    std::list<std::pair<int, std::string>> data = {
        {1, "Value1"},
        {2, "Value2"}
    };
    sorted<int, std::string> table(data);
    EXPECT_EQ(table.find(1).second, "Value1");
    EXPECT_EQ(table.find(2).second, "Value2");
    EXPECT_EQ(table.get_size(), 2);
}