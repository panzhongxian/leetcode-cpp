#include "base.h"

class Solution {
 public:
  int findLucky(vector<int>& arr) {
    map<int, int> m;
    for (int num : arr) {
      m[num]++;
    }
    int ret = -1;
    for (auto kv : m) {
      if (kv.first == kv.second) {
        ret = kv.first;
      }
    }
    return ret;
  }
};
