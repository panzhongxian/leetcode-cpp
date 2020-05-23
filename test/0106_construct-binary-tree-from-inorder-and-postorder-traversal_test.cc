#include "0106_construct-binary-tree-from-inorder-and-postorder-traversal.h"

TEST(S, Demo) {
  Solution s;
  vector<int> v1({9, 3, 15, 20, 7}), v2({9, 15, 7, 20, 3});
  s.buildTree(v1, v2);
  //
}
