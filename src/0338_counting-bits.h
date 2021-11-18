#include "base.h"

class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> ret{0};
    if (n == 0) {
      return ret;
    }
    int base = 1;
    while (true) {
      for (int i = 0; i < base; i++) {
        ret.push_back(ret[i] + 1);
        if (ret.size() == n + 1) {
          return ret;
        }
      }
      base <<= 1;
    }
    return ret;
  }
};
