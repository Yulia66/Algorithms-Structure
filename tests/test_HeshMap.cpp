#include <gtest.h>
#include "../lib_HeshMap/HeshMap.h"

TEST(LinkTest, InsertAndPrint) {
    Link<std::string, int> link;
    link.insert("key1", 1);
    link.insert("key2", 2);

    testing::internal::CaptureStdout();
    link.print_chain();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Key: key1, Value: 1"), std::string::npos);
    EXPECT_NE(output.find("Key: key2, Value: 2"), std::string::npos);
}

TEST(HeshTableTest, InsertAndPrint) {
    Hesh_table<std::string, int> table;
    table.insert("key1", 1);
    table.insert("key2", 2);

    testing::internal::CaptureStdout();
    table.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Key: key1, Value: 1"), std::string::npos);
    EXPECT_NE(output.find("Key: key2, Value: 2"), std::string::npos);
}

TEST(HeshTableTest, InsertWithCollision) {
    Hesh_table<int, int> table;
    int index1 = table.insert(1, 100);
    int index2 = table.insert(1 + CAPACITY, 200); 
    EXPECT_EQ(index1, index2);
    testing::internal::CaptureStdout();
    table.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Key: 1, Value: 100"), std::string::npos);
    EXPECT_NE(output.find("Key: 51, Value: 200"), std::string::npos);
}

TEST(HeshTableTest, UnsupportedKeyType) {
    EXPECT_THROW(Hesh_function(3.14), std::logic_error);
}
