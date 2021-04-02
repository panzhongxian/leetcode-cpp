#include "base.h"

class Solution {
 public:
  vector<int> findErrorNums(vector<int>& nums) {
    vector<int> num_cnt(nums.size(), 0);
    int n1, n2;
    for (int i : nums) {
      num_cnt[i - 1]++;
    }
    for (int i = 1; i <= num_cnt.size(); ++i) {
      if (num_cnt[i - 1] == 0) {
        n2 = i;
        continue;
      }
      if (num_cnt[i - 1] == 2) {
        n1 = i;
      }
    }
    return {n1, n2};
  }
};
