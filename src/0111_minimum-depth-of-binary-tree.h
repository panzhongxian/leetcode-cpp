#include "base.h"

typedef base::TreeNode<int> TreeNode;

class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (!root) {
      return 0;
    }

    vector<TreeNode*> level_traversal;
    level_traversal.push_back(root);
    int start_idx = 0;
    int end_idx;
    int cur_depth = 0;

    while (start_idx < level_traversal.size()) {
      end_idx = level_traversal.size();
      cur_depth++;
      TreeNode* cur_node;
      for (int i = start_idx; i < end_idx; ++i) {
        cur_node = level_traversal[i];
        if (cur_node->left == nullptr && cur_node->right == nullptr) {
          return cur_depth;
        }
        if (cur_node->left) {
          level_traversal.push_back(cur_node->left);
        }
        if (cur_node->right) {
          level_traversal.push_back(cur_node->right);
        }
      }
      start_idx = end_idx;
    }
    assert(false);
  }
};
