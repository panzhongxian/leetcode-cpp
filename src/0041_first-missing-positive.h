#include "base.h"

class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > nums.size() || nums[i] < 0) {
        nums[i] = 0;
      }
    }
    for (int i = 0; i < nums.size();) {
      if (nums[i] == 0 || nums[i] == i + 1) {
        i++;
        continue;
      }
      auto curr_num = nums[i];
      nums[i] = 0;
      int next_num;
      while (curr_num != 0 && curr_num != nums[curr_num - 1]) {
        next_num = nums[curr_num - 1];
        nums[curr_num - 1] = curr_num;
        curr_num = next_num;
      }
    }
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) {
        return i + 1;
      }
    }
    return nums.size() + 1;
  }
};
