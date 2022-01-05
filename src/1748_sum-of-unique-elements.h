#include "base.h"

class Solution {
 public:
  int sumOfUnique(vector<int>& nums) {
    unordered_map<int, int> m;
    int ret = 0;
    for (int num : nums) {
      m[num]++;
    }
    for (auto kv : m) {
      if (kv.second == 1) {
        ret += kv.first;
      }
    }
    return ret;
  }
};
