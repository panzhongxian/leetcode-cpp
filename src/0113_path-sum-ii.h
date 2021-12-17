#include "base.h"

typedef base::TreeNode<int> TreeNode;

class Solution {
  struct SumSerial {
    SumSerial(int sum) : sum(sum) { serial.push_back(sum); };
    SumSerial() : sum(0){};
    int sum;
    vector<int> serial;
    void InsertNewVal(int node_val) {
      sum += node_val;
      serial.push_back(node_val);
    }
  };

 public:
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> ret;
    if (!root) {
      // test case (null, 0) -> false
      return ret;
    }

    vector<TreeNode*> level_traversal({root});
    vector<SumSerial> level_traversal_sum_serial({SumSerial(root->val)});

    int start_idx = 0;
    int end_idx;

    while (start_idx < level_traversal.size()) {
      end_idx = level_traversal.size();
      TreeNode* cur_node;
      for (int i = start_idx; i < end_idx; ++i) {
        cur_node = level_traversal[i];
        // SumSerial &cur_node_sum_serial = level_traversal_sum_serial[i];
        // 为什么这里用引用会有问题？段错误
        SumSerial cur_node_sum_serial = level_traversal_sum_serial[i];
        if (cur_node->left == nullptr && cur_node->right == nullptr) {
          if (cur_node_sum_serial.sum == sum) {
            ret.push_back(cur_node_sum_serial.serial);
          }
          continue;
        }

        cout << start_idx << ":" << end_idx << ":" << i << ":"
             << cur_node_sum_serial.sum << endl;

        if (cur_node->left) {
          level_traversal.push_back(cur_node->left);
          SumSerial left_sum_serial(cur_node_sum_serial);
          left_sum_serial.InsertNewVal(cur_node->left->val);
          level_traversal_sum_serial.push_back(left_sum_serial);
        }
        if (cur_node->right) {
          level_traversal.push_back(cur_node->right);
          SumSerial right_sum_serial(cur_node_sum_serial);
          right_sum_serial.InsertNewVal(cur_node->right->val);
          level_traversal_sum_serial.push_back(right_sum_serial);
        }
      }
      start_idx = end_idx;
    }
    return ret;
  }
};
