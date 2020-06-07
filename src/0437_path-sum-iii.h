#include "base.h"

typedef base::TreeNode<int> TreeNode;
class Solution {
  int sum;

 public:
  int CountSumToLeaf(TreeNode* root, int cur_sum,
                     unordered_map<int, int>& prefix_sum_count) {
    int ret = 0;
    if (!root) {
      return ret;
    }
    cur_sum += root->val;
    if (prefix_sum_count.count(cur_sum - sum)) {
      ret += prefix_sum_count[cur_sum - sum];
    }

    if (prefix_sum_count.count(cur_sum) == 0) {
      prefix_sum_count[cur_sum] = 0;
    }
    prefix_sum_count[cur_sum]++;
    ret += CountSumToLeaf(root->left, cur_sum, prefix_sum_count);
    ret += CountSumToLeaf(root->right, cur_sum, prefix_sum_count);
    prefix_sum_count[cur_sum]--;

    return ret;
  }

  int pathSum(TreeNode* root, int sum) {
    this->sum = sum;
    unordered_map<int, int> prefix_sum_count = {{0, 1}};
    return CountSumToLeaf(root, 0, prefix_sum_count);
  }
};
