#include "base.h"

class Solution {
 public:
  vector<vector<int>> subsets(const vector<int>& nums) {
    assert(nums.size() < 32);
    size_t max_weight = (int)pow(2, nums.size());

    vector<vector<int>> ret;
    for (size_t i = 0; i < max_weight; ++i) {
      vector<int> v;
      size_t idx = 0;
      for (size_t j = i; j > 0;) {
        if (j % 2) {
          v.push_back(nums[idx]);
        };
        idx++;
        j >>= 1;
      }
      ret.push_back(v);
    }
    return ret;
  }
};

class Solution2 {
 private:
  vector<vector<int>> ret;
  vector<int> nums;

  void backtracking(vector<int> left, int start_idx) {
    ret.push_back(left);
    for (size_t i = start_idx; i < nums.size(); ++i) {
      left.push_back(nums[i]);
      backtracking(left, start_idx + 1);
      left.pop_back();
    }
  }

 public:
  vector<vector<int>> subsets(const vector<int>& nums) {
    this->nums = nums;
    ret.clear();
    vector<int> left;
    backtracking(left, 0);
    return ret;
  }
};
