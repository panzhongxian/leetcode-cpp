#include "base.h"
typedef base::TreeNode<int> TreeNode;

class Solution {
 public:
  bool isUnivalTree(TreeNode* root) {
    if (!root) {
      return true;
    }
    if (root->left) {
      ret &= root->val == root->left->val;
      ret &= isUnivalTree(root->left);
    }

    if (root->right) {
      ret &= root->val == root->right->val;
      ret &= isUnivalTree(root->right);
    }
    return ret;
  }
};
