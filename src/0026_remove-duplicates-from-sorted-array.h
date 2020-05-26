#include "base.h"
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }
    int ret = 0;
    for (size_t i = 1; i < nums.size(); ++i) {
      if (nums[i] != nums[ret]) {
        nums[++ret] = nums[i];
      }
    }
    return ret;
  }
};
