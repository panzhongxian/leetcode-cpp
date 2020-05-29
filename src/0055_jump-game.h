#include "base.h"

class Solution {
 public:
  bool canJump(const vector<int>& nums) {
    vector<int> reachable_idx_vec(nums.size());
    size_t max_reachable_idx = 0;
    size_t next_max_reachable_idx;
    reachable_idx_vec[0] = 1;

    for (size_t i = 0; i < nums.size(); ++i) {
      if (!reachable_idx_vec[i]) {
        continue;
      }

      next_max_reachable_idx = max(max_reachable_idx, i + nums[i]);
      if (next_max_reachable_idx + 1 >= nums.size()) {
        return true;
      }

      if (next_max_reachable_idx <= max_reachable_idx) {
        continue;
      }

      for (size_t j = max_reachable_idx; j <= next_max_reachable_idx; ++j) {
        reachable_idx_vec[j] = 1;
      }
      max_reachable_idx = next_max_reachable_idx;
    }
    return false;
  }
};
