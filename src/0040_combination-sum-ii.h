#include "base.h"

class Solution {
 private:
  int target;
  vector<int> candidates;
  vector<vector<int>> ret;
  void backtracking(vector<int> left, int sum, int remain, int start_idx) {
    if (sum == target) {
      ret.push_back(left);
      return;
    }

    if (sum > target || (sum + remain < target) ||
        start_idx == candidates.size()) {
      return;
    }

    int cur_num = candidates[start_idx];
    size_t next_idx = start_idx + 1;
    remain -= cur_num;
    left.push_back(cur_num);
    backtracking(left, sum + cur_num, remain, next_idx);

    left.pop_back();
    while (next_idx < candidates.size() && cur_num == candidates[next_idx]) {
      remain -= cur_num;
      next_idx++;
    }

    backtracking(left, sum, remain, next_idx);
  }

 public:
  vector<vector<int>> combinationSum2(const vector<int>& candidates,
                                      int target) {
    this->target = target;
    this->candidates = candidates;
    this->ret.clear();
    sort(this->candidates.begin(), this->candidates.end());

    int remain = 0;
    for (auto i : candidates) {
      remain += i;
    }
    backtracking(vector<int>(), 0, remain, 0);
    return ret;
  }
};
