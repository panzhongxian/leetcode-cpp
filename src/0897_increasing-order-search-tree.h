#include "base.h"
typedef base::TreeNode<int> TreeNode;

class Solution {
public:
  TreeNode *increasingBST(TreeNode *root, TreeNode **tail = nullptr) {
    TreeNode *ret = nullptr;
    if (root == nullptr) {
      return ret;
    }

    TreeNode *tail_ptr;
    if (root->left) {
      ret = increasingBST(root->left, &tail_ptr);
      tail_ptr->right = root;
    } else {
      ret = root;
    }
    tail_ptr = root;
    root->left = nullptr;

    if (root->right) {
      TreeNode *new_tail_ptr;
      tail_ptr->right = increasingBST(root->right, &new_tail_ptr);
      tail_ptr = new_tail_ptr;
      tail_ptr->right = nullptr;
    }

    if (tail) {
      *tail = tail_ptr;
    }
    return ret;
  }
};
