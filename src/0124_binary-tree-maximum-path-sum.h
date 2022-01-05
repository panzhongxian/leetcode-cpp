#include "base.h"
typedef base::TreeNode<int> TreeNode;

class Solution {
  int max_path_sum;

 public:
  int maxPathSum(TreeNode* root) {
    assert(root);
    max_path_sum = root->val;
    MaxPathToRoot(root);
    return max_path_sum;
  }

  int MaxPathToRoot(TreeNode* root) {
    if (!root) {
      return 0;
    }
    int path_sum = root->val;
    int path_left = MaxPathToRoot(root->left);
    int path_right = MaxPathToRoot(root->right);
    if (path_left > 0) {
      path_sum += path_left;
    }
    if (path_right > 0) {
      path_sum += path_right;
    }
    if (path_sum > max_path_sum) {
      max_path_sum = path_sum;
    }
    return root->val + max(max(path_left, path_right), 0);
  }
};
