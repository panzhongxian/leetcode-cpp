#include "0105_construct-binary-tree-from-preorder-and-inorder-traversal.h"

TEST(S, Demo) {
  Solution s;
  vector<int> v1({3, 9, 20, 15, 7}), v2({9, 3, 15, 20, 7});
  s.buildTree(v1, v2);
  //
}
