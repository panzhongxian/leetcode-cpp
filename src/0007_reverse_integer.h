#include "base.h"
// constexpr int upper_limit = pow(2, 31) - 1;  // 2147483647
// constexpr int lower_limit = -pow(2, 31);     // -2147483648
const int upper_limit = 2147483647;
const int lower_limit = -2147483648;

class Solution {
 public:
  int reverse(int x) {
    int ret = 0;
    int mod;
    bool neg_flag = x < 0;
    if (neg_flag) {
      if (x == lower_limit) {
        return 0;
      }
      x = -x;
    }

    while (x) {
      mod = x % 10;
      x = x / 10;
      if (ret > (upper_limit - mod) / 10) {
        return 0;
      }
      ret = ret * 10 + mod;
    }

    return neg_flag ? -ret : ret;
  }
};
