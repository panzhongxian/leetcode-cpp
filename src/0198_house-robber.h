#include "base.h"
class Solution {
 public:
  int rob(const vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }
    if (nums.size() == 1) {
      return nums[0];
    }

    vector<int> max_wealth(nums.size());
    max_wealth[0] = nums[0];
    max_wealth[1] = max(nums[0], nums[1]);
    for (size_t i = 2; i < nums.size(); ++i) {
      max_wealth[i] = max(max_wealth[i - 1], (max_wealth[i - 2] + nums[i]));
    }
    return max_wealth.back();
  }
};
