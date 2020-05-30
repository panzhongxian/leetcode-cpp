#include "base.h"

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    if (nums.size() < 2) {
      return;
    }
    size_t zero_pos = 0;
    size_t non_zero_pos = 0;
    while (zero_pos < nums.size() && non_zero_pos < nums.size()) {
      while (nums[zero_pos] != 0) {
        zero_pos++;
        if (zero_pos >= nums.size()) {
          return;
        }
      }
      non_zero_pos = zero_pos;
      while (nums[non_zero_pos] == 0) {
        non_zero_pos++;
        if (non_zero_pos >= nums.size()) {
          return;
        }
      }
      swap(nums[zero_pos++], nums[non_zero_pos++]);
    }
  }
};
