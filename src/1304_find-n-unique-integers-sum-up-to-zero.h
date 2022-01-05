#include "base.h"

class Solution {
 public:
  vector<int> sumZero(int n) {
    vector<int> ret;
    if (n & 1) {
      ret.push_back(0);
    }
    n >>= 1;
    for (int i = 1; i <= n; i++) {
      ret.push_back(i);
      ret.push_back(-i);
    }
    return ret;
  }
};
