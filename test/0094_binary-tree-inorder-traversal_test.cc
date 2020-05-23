#include "0094_binary-tree-inorder-traversal.h"
typedef base::TreeNode<int> TreeNode;

TEST(S, Demo) {
  TreeNode* t = base::TreeNodeFactory<int>("[1,2,3,4,5,null,6]");
  Solution s;
  EXPECT_EQ(s.inorderTraversal(t), vector<int>({4, 2, 5, 1, 3, 6}));
}
