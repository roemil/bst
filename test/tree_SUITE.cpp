#include <gtest/gtest.h>
#include "tree.h"
#include <iostream>
#include <vector>
#include <queue>
#include <bitset>

TEST(CodecTest, BitSetTest){
    std::bitset<5> BitSet {"1010"};
    EXPECT_EQ(0xA, BitSet);
}

bool is_tree_equal(node* lNode, node* rNode){
    if(lNode == nullptr && rNode == nullptr){
        return true;
    }else if(lNode->freq == rNode->freq && lNode->ch == rNode->ch){
        if(is_tree_equal(lNode->left, rNode->left) &&
           is_tree_equal(lNode->right, rNode->right)){
            return true;
           }else{
            return false;
           }
    }else{
        return false;
    }
}

template <typename Tree>
bool tree_compare (Tree &lhs, Tree &rhs) {
    // No predicate needed because there is operator== for pairs already.
    node* lRoot = lhs.get_root();
    node * rRoot = rhs.get_root();
    return lhs.size() == rhs.size() && is_tree_equal(lRoot, rRoot);
}

TEST(TreeTest, CompareTrees){
    Tree TreeA;
    TreeA.insert('A', 3);
    TreeA.insert('b', 3);
    TreeA.insert('c', 2);
    TreeA.insert('d', 1);
    TreeA.insert('e', 5);

    Tree TreeB;
    TreeB.insert('A', 3);
    TreeB.insert('b', 3);
    TreeB.insert('c', 2);
    TreeB.insert('d', 1);
    TreeB.insert('e', 5);

    EXPECT_EQ(5, TreeA.size());
    EXPECT_EQ(true, tree_compare(TreeA, TreeB));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}