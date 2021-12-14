#include "base.h"
class Solution {
public:
  int find_increasing_breakpoint(const vector<int> &nums, int skip_index = -1) {
    int prev = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
      if (i == skip_index) {
        continue;
      }
      if (nums[i] <= prev) {
        return i;
      }
      prev = nums[i];
    }
    return -1;
  }

  bool canBeIncreasing(vector<int> &nums) {
    int break_point = find_increasing_breakpoint(nums);
    if (break_point == -1) {
      return true;
    }
    return find_increasing_breakpoint(nums, break_point) == -1 ||
           find_increasing_breakpoint(nums, break_point - 1) == -1;
  }
};
