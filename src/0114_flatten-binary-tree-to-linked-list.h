#include "base.h"

typedef base::TreeNode<int> TreeNode;

class Solution {
 public:
  void flatten(TreeNode* root) {
    if (!root ||  //
        (root->left == nullptr && root->right == nullptr)) {
      return;
    }

    flatten(root->left);
    flatten(root->right);

    // 测试用例要求 `根->左子树链表->右子树链表`
    swap(root->left, root->right);

    if (root->left == nullptr) {
      return;
    }

    if (root->right == nullptr) {
      swap(root->left, root->right);
    }

    TreeNode* cur_parent_of_right = root;
    while (cur_parent_of_right->right) {
      cur_parent_of_right = cur_parent_of_right->right;
    }

    swap(root->left, cur_parent_of_right->right);
  }
};
