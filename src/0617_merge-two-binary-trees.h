#include "base.h"
typedef base::TreeNode<int> TreeNode;

class Solution {
 public:
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) {
      return nullptr;
    }
    TreeNode* ret = new TreeNode;
    if (t1 && t2) {
      ret->val = t1->val + t2->val;
      ret->left = mergeTrees(t1->left, t2->left);
      ret->right = mergeTrees(t1->right, t2->right);
      return ret;
    } else if (t1) {
      return t1;
    } else {
      return t2;
    }
  }
};
