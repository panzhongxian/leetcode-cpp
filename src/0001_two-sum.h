#include "base.h"
class Solution {
 public:
  vector<int> twoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> num_idx_mp;
    for (int i = 0; i < nums.size(); ++i) {
      int res = target - nums[i];
      if (num_idx_mp.count(res) > 0) {
        return vector<int>({num_idx_mp[res], i});
      }
      num_idx_mp[nums[i]] = i;
    }
    return vector<int>();
  }
};
