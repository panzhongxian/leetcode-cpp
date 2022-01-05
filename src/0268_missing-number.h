#include "base.h"

class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    nums.push_back(-1);
    for (int p = 0; p < nums.size(); ++p) {
      while (nums[p] != -1 && nums[nums[p]] != nums[p]) {
        swap(nums[p], nums[nums[p]]);
      }
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == -1) {
        return i;
      }
    }
    return -1;
  }
};
