#include "base.h"

class Solution {
  vector<vector<int>> ret;
  vector<int> candidates;
  int target;
  void backtracking(vector<int> cur_vec, int cur_weight, int start_idx) {
    if (cur_weight > target) {
      return;
    }

    for (size_t i = start_idx; i < candidates.size(); ++i) {
      int cur_num = candidates[i];
      if (cur_weight + cur_num > target) {
        continue;
      }
      cur_vec.push_back(cur_num);
      if (cur_weight + cur_num == target) {
        ret.push_back(cur_vec);
      } else {
        backtracking(cur_vec, cur_weight + cur_num, i);
      }
      cur_vec.pop_back();
    }
  }

 public:
  vector<vector<int>> combinationSum(const vector<int>& candidates,
                                     int target) {
    this->candidates = candidates;
    this->ret.clear();
    this->target = target;
    sort(this->candidates.begin(), this->candidates.end());
    backtracking(vector<int>(), 0, 0);
    return ret;
  }
};
