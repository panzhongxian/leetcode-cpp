#include "base.h"
typedef base::TreeNode<int> TreeNode;

class Solution {
 public:
  Solution() : prev_node_(NULL) {}
  int minDiffInBST(TreeNode* root) {
    if (!root) {
      return 0;
    }
    if (root->left) {
      min_diff_ = root->val - root->left->val;
    } else if (root->right) {
      min_diff_ = root->right->val - root->val;
    } else {
      return 0;
    }
    InOrderTraversal(root);
    return min_diff_;
  }
  void InOrderTraversal(TreeNode* root) {
    if (root == NULL) {
      return;
    }
    if (root->left) {
      InOrderTraversal(root->left);
    }
    if (prev_node_) {
      min_diff = min(root->val - prev_node_->val, min_diff);
    }
    prev_node_ = root;
    if (root->right) {
      InOrderTraversal(root->right);
    }
  }

 private:
  TreeNode* prev_node_;
  int min_diff_;
};
