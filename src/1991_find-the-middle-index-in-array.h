#include "base.h"

class Solution {
 public:
  int findMiddleIndex(vector<int>& nums) {
    int sum = 0;

    for (int i : nums) {
      sum += i;
    }
    int left_sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      int k = sum - nums[i];
      if (k & 1) {
        left_sum += nums[i];
        continue;
      }
      k >>= 1;
      if (k == left_sum) {
        return i;
      }
      left_sum += nums[i];
    }
    return -1;
  }
};
