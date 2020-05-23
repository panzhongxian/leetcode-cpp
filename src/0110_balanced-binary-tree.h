#include "base.h"

typedef base::TreeNode<int> TreeNode;

class Solution {
 public:
  bool isBalancedWithHeight(TreeNode* root, int& height) {
    if (!root) {
      height = 0;
      return true;
    }

    int height_left, height_right;
    if (!isBalancedWithHeight(root->left, height_left) ||
        !isBalancedWithHeight(root->right, height_right)) {
      return false;
    }

    if (height_left > height_right) {
      height = height_left + 1;
      return height_left - height_right <= 1;
    } else {
      height = height_right + 1;
      return height_right - height_left <= 1;
    }
  }

  bool isBalanced(TreeNode* root) {
    int height;
    return isBalancedWithHeight(root, height);
  }
};
