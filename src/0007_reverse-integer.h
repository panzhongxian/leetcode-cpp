#include "base.h"

class Solution {
 public:
  int reverse(int x) {
    int ret = 0;
    int mod;
    bool neg_flag = x < 0;
    if (neg_flag) {
      if (x == INT32_MIN) {
        return 0;
      }
      x = -x;
    }

    while (x) {
      mod = x % 10;
      x = x / 10;
      if (ret > (INT32_MAX - mod) / 10) {
        return 0;
      }
      ret = ret * 10 + mod;
    }

    return neg_flag ? -ret : ret;
  }
};
