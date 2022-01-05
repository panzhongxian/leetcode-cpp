#include "base.h"
typedef base::TreeNode<int> TreeNode;
class Solution {
 public:
  bool CheckInTree(TreeNode* root, TreeNode* p) {
    if (!root) {
      return false;
    }
    if (root == p) {
      return true;
    }
    return CheckInTree(root->left, p) || CheckInTree(root->right, p);
  }

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == p) {
      return p;
    }
    if (root == q) {
      return q;
    }
    bool p_in_left = CheckInTree(root->left, p);
    bool q_in_left = CheckInTree(root->left, q);
    if (p_in_left && q_in_left) {
      return lowestCommonAncestor(root->left, p, q);
    } else if (!p_in_left && !q_in_left) {
      return lowestCommonAncestor(root->right, p, q);
    }
    return root;
  }
};
