#include "base.h"

class Solution {
 public:
  int numIdenticalPairs(vector<int>& nums) {
    unordered_map<int, int> m;
    for (int num : nums) {
      m[num]++;
    }
    int ret = 0;
    for (auto kv : m) {
      if (kv.second > 1) {
        ret += kv.second * (kv.second - 1) / 2;
      }
    }
    return ret;
  }
};
