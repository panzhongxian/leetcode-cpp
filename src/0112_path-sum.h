#include "base.h"

typedef base::TreeNode<int> TreeNode;

class Solution {
 public:
  bool hasPathSum(TreeNode* root, int sum) {
    if (!root) {
      return false;  // test case (null, 0) -> false
    }

    vector<TreeNode*> level_traversal({root});
    vector<int> level_traversal_sum_from_root({root->val});

    int start_idx = 0;
    int end_idx;

    while (start_idx < level_traversal.size()) {
      end_idx = level_traversal.size();
      TreeNode* cur_node;
      int cur_node_sum;
      for (int i = start_idx; i < end_idx; ++i) {
        cur_node = level_traversal[i];
        cur_node_sum = level_traversal_sum_from_root[i];
        if (cur_node->left == nullptr && cur_node->right == nullptr) {
          if (cur_node_sum == sum) {
            return true;
          }
          continue;
        }

        cout << start_idx << ":" << end_idx << ":" << i << ":" << cur_node_sum
             << endl;

        if (cur_node->left) {
          level_traversal.push_back(cur_node->left);
          level_traversal_sum_from_root.push_back(cur_node_sum +
                                                  cur_node->left->val);
        }
        if (cur_node->right) {
          level_traversal.push_back(cur_node->right);
          level_traversal_sum_from_root.push_back(cur_node_sum +
                                                  cur_node->right->val);
        }
      }
      start_idx = end_idx;
    }
    return false;
  }
};
