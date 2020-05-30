#include "base.h"

class Solution {
 public:
  int subarraySum(const vector<int>& nums, int k) {
    int ret = 0;

    int pre_weight = 0;
    int weight;

    unordered_map<int, int> first_idx;
    first_idx[0] = 1;

    for (int i = 0; i < nums.size(); ++i) {
      weight = pre_weight + nums[i];
      pre_weight = weight;
      if (first_idx.count(weight) == 0) {
        first_idx[weight] = 0;
      }

      int to_find = weight - k;

      if (first_idx.count(to_find) > 0) {
        ret += first_idx[to_find];
      }

      first_idx[weight]++;
    }
    return ret;
  }
};
