#include "base.h"

class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    assert(nums.size() >= 2);
    if (nums.size() == 2) {
      return 1;
    }
    int n = nums.size() - 1;
    int sum = (n + 1) * n / 2;
    for (auto i : nums) {
      sum -= i;
    }

    return -sum;
  }
};
