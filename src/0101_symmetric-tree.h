#include "base.h"

typedef base::TreeNode<int> TreeNode;

class Solution {
 public:
  bool areaMirror(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
      return true;
    }

    if ((!p && q) || (p && !q) || (p->val != q->val) ||
        !areaMirror(p->left, q->right) || !areaMirror(p->right, q->left)) {
      return false;
    }

    return true;
  }

  bool isSymmetric(TreeNode* root) {
    if (!root) {
      return true;
    }
    return areaMirror(root->left, root->right);
  }
};
