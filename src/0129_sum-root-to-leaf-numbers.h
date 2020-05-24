#include "base.h"

typedef base::TreeNode<int> TreeNode;

class Solution {
 public:
  int sumNumbers(TreeNode *root) {
    int ret = 0;
    if (!root) {
      return ret;
    }

    vector<TreeNode *> level_traversal({root});
    vector<int> level_traversal_base({root->val});

    int start_idx = 0;
    int end_idx;

    while (start_idx < level_traversal.size()) {
      end_idx = level_traversal.size();
      TreeNode *cur_node;
      for (int i = start_idx; i < end_idx; ++i) {
        cur_node = level_traversal[i];
        // 为什么这里用引用会有问题？段错误
        int base = level_traversal_base[i];
        if (cur_node->left == nullptr && cur_node->right == nullptr) {
          ret += level_traversal_base[i];
          continue;
        }

        if (cur_node->left) {
          level_traversal.push_back(cur_node->left);
          level_traversal_base.push_back(base * 10 + cur_node->left->val);
        }
        if (cur_node->right) {
          level_traversal.push_back(cur_node->right);
          level_traversal_base.push_back(base * 10 + cur_node->right->val);
        }
      }
      start_idx = end_idx;
    }
    return ret;
  }
};
