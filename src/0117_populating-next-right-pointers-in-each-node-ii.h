#include "base.h"

typedef base::TreeNode<int> Node;

class Solution {
 public:
  Node* connect(Node* root) {
    if (!root) {
      return root;
    }

    vector<Node*> level_traversal({root});

    int start_idx = 0;
    int end_idx;

    while (start_idx < level_traversal.size()) {
      end_idx = level_traversal.size();
      Node* cur_node;
      for (size_t i = start_idx; i < end_idx; ++i) {
        cur_node = level_traversal[i];

        if (cur_node->left) {
          level_traversal.push_back(cur_node->left);
        }
        if (cur_node->right) {
          level_traversal.push_back(cur_node->right);
        }
      }

      for (size_t i = start_idx; i + 1 < end_idx; ++i) {
        level_traversal[i]->next = level_traversal[i + 1];
      }

      start_idx = end_idx;
    }

    for (size_t i = start_idx; i + 1 < level_traversal.size(); ++i) {
      level_traversal[i]->next = level_traversal[i + 1];
    }

    return root;
  }
};
