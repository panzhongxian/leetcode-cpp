#include "base.h"

class Solution {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }
    // [left, right)
    int ret = nums.size() + 1;
    int left = 0;
    int right = 0;
    int sum = 0;
    while (right < nums.size()) {
      sum += nums[right++];
      if (sum < s) {
        continue;
      }
      while (sum >= s && left < right) {
        int len = right - left;
        if (len < ret) {
          ret = len;
        }
        if (sum - nums[left] >= s) {
          sum -= nums[left++];
        } else {
          break;
        }
      }
    }

    return ret <= nums.size() ? ret : 0;
  }
};
