#include "base.h"

class Solution {
 public:
  int findMaxLength(const vector<int>& nums) {
    if (nums.size() < 2) {
      return 0;
    }
    int weight, pre_weight;
    // map<int, int> first_idx;
    unordered_map<int, int> first_idx;  // very important.

    first_idx[0] = 0;
    pre_weight = 0;

    int ret = 0;
    for (size_t i = 1; i <= nums.size(); ++i) {
      weight = pre_weight + ((nums[i - 1] == 0) ? -1 : 1);
      pre_weight = weight;
      // cout << "i: " << i << ", weight: " << weight << endl;

      if (first_idx.count(weight) == 0) {
        first_idx[weight] = i;
        continue;
      }
      int diff = i - first_idx[weight];
      if (diff > ret) {
        ret = diff;
      }
    }
    return ret;
  }
};
