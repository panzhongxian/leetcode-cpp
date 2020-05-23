#include "base.h"

typedef base::TreeNode<int> TreeNode;

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) {
      return vector<vector<int>>();
    }
    vector<vector<int>> ret;
    vector<TreeNode*> cur_layer, next_layer;
    cur_layer.push_back(root);
    vector<int> cur_layer_val_vec;

    while (cur_layer.size()) {
      cur_layer_val_vec.clear();
      next_layer.clear();

      for (auto node : cur_layer) {
        cur_layer_val_vec.push_back(node->val);
        if (node->left) {
          next_layer.push_back(node->left);
        }
        if (node->right) {
          next_layer.push_back(node->right);
        }
      }
      cur_layer = move(next_layer);
      ret.push_back(move(cur_layer_val_vec));
    }
    return ret;
  }
};
