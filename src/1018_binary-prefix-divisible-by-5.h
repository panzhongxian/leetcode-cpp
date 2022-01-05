#include "base.h"

class Solution {
 public:
  vector<bool> prefixesDivBy5(vector<int>& nums) {
    vector<bool> ret;
    int sum_remaining = 0;
    for (int num : nums) {
      sum_remaining <<= 1;
      sum_remaining += num;
      sum_remaining %= 5;
      ret.push_back(sum_remaining == 0);
    }
    return ret;
  }
};
