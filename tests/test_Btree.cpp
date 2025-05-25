#include <gtest.h>
#include "../lib_Btree/Btree.h"


TEST(BTreeNodeTest, InsertAndSearch) {
    BTreeNode<int>* root = nullptr;
    root = root->insert(root, 1);
    root = root->insert(root, 6);
    root = root->insert(root, 3);
    root = root->insert(root, 4);
    root = root->insert(root, 2);
    EXPECT_NE(root->search(root, 1), nullptr);
    EXPECT_NE(root->search(root, 6), nullptr);
    EXPECT_NE(root->search(root, 3), nullptr);
    EXPECT_NE(root->search(root, 4), nullptr);
    EXPECT_NE(root->search(root, 2), nullptr);

    EXPECT_EQ(root->search(root, 10), nullptr);
}

TEST(BTreeNodeTest, Erase) {
    BTreeNode<int>* root = nullptr;
    root = root->insert(root, 1);
    root = root->insert(root, 6);
    root = root->insert(root, 3);
    root = root->insert(root, 4);
    root = root->insert(root, 2);

    root = root->erase(root, 3);
    EXPECT_EQ(root->search(root, 3), nullptr);

    root = root->erase(root, 10);
    EXPECT_NE(root->search(root, 1), nullptr);
    EXPECT_NE(root->search(root, 6), nullptr);
    EXPECT_NE(root->search(root, 4), nullptr);
    EXPECT_NE(root->search(root, 2), nullptr);
}

TEST(BTreeNodeTest, Clear) {
    BTreeNode<int>* root = nullptr;
    root = root->insert(root, 1);
    root = root->insert(root, 6);
    root = root->insert(root, 3);
    root = root->insert(root, 4);
    root = root->insert(root, 2);

    root->clear();

    EXPECT_THROW(root->print(root), std::logic_error);
}

TEST(BTreeNodeTest, Min) {
    BTreeNode<int>* root = nullptr;
    root = root->insert(root, 1);
    root = root->insert(root, 6);
    root = root->insert(root, 3);
    root = root->insert(root, 4);
    root = root->insert(root, 2);

    EXPECT_EQ(root->Min(root)->getValue(), 1);
}
// структура дерева 
