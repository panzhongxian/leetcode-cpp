#include "base.h"

class Solution {
  vector<int> nums;
  vector<vector<int>> ret;

 public:
  void backtracking(vector<int> left, int start) {
    ret.push_back(left);
    for (size_t i = start; i < nums.size(); ++i) {
      if (i > start && nums[i] == nums[i - 1]) continue;  // skip duplicates
      left.push_back(nums[i]);
      backtracking(left, i + 1);
      left.pop_back();
    }
  }
  vector<vector<int>> subsetsWithDup(const vector<int>& nums) {
    this->nums = nums;
    ret.clear();
    backtracking(vector<int>(), 0);
    return ret;
  }
};
