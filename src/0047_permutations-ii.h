#include "base.h"

// 其实就是[0, 1, 2, 3, ...]的全排列

class Solution {
  vector<vector<int>> ret;
  vector<int> nums;

 public:
  void backtracking(size_t start) {
    if (start == nums.size()) {
      ret.push_back(nums);
      return;
    }
    unordered_set<int> used;
    for (size_t i = start; i < nums.size(); ++i) {
      if (i > start && used.find(nums[i]) != used.end()) {
        continue;
      }
      used.insert(nums[i]);
      swap(nums[start], nums[i]);
      backtracking(start + 1);
      swap(nums[start], nums[i]);
    }
  }
  vector<vector<int>> permuteUnique(const vector<int>& nums) {
    ret.clear();
    this->nums = nums;
    sort(this->nums.begin(), this->nums.end());
    backtracking(0);
    return ret;
  }
};
