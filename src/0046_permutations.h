#include "base.h"

// 其实就是[0, 1, 2, 3, ...]的全排列

class Solution {
  vector<vector<int>> ret;
  vector<int> nums;

 public:
  void backtracking(int start) {
    if (start == nums.size()) {
      ret.push_back(nums);
    }
    for (size_t i = start; i < nums.size(); ++i) {
      swap(nums[start], nums[i]);
      backtracking(start + 1);
      swap(nums[start], nums[i]);
    }
  }
  vector<vector<int>> permute(const vector<int>& nums) {
    ret.clear();
    this->nums = nums;
    backtracking(0);
    return ret;
  }
};
