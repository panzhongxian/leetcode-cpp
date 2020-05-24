#include "0144_binary-tree-preorder-traversal.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.preorderTraversal(base::TreeNodeFactory<int>("[]")),
            vector<int>());
  EXPECT_EQ(s.preorderTraversal(base::TreeNodeFactory<int>("[1]")),
            vector<int>({1}));
  EXPECT_EQ(s.preorderTraversal(base::TreeNodeFactory<int>("[1,2,null]")),
            vector<int>({1, 2}));
  EXPECT_EQ(s.preorderTraversal(base::TreeNodeFactory<int>("[1,null,2]")),
            vector<int>({1, 2}));
  EXPECT_EQ(s.preorderTraversal(base::TreeNodeFactory<int>("[1,null,2,3]")),
            vector<int>({1, 2, 3}));
}
