#include "base.h"

class Solution {
 public:
  int countKDifference(vector<int>& nums, int k) {
    map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
      if (m.find(nums[i]) == m.end()) {
        m[nums[i]] = 1;
      } else {
        m[nums[i]]++;
      }
    }

    int ret = 0;
    for (auto& kv : m) {
      if (k == 0) {
        ret += kv.second * (kv.second - 1);
        continue;
      }
      if (m.find(kv.first + k) != m.end()) {
        ret += kv.second * m[kv.first + k];
      }
    }
    return ret;
  }
};
