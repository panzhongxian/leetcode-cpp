#include "base.h"

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    assert(nums.size() > 0);

    // max_sum[i] means max(sum from x to i)
    // max_sum[i] = max_sum[i - 1] < 0 ? nums[i] : nums[i] + max_sum[i-1]
    vector<int> max_sum(nums.size());
    max_sum[0] = nums[0];
    int ret = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
      max_sum[i] = (max_sum[i - 1] < 0) ? nums[i] : (nums[i] + max_sum[i - 1]);
      if (max_sum[i] > ret) {
        ret = max_sum[i];
      }
    }
    return ret;
  }
};
