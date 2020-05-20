#include "base.h"
constexpr int upper_limit = pow(2, 31) - 1;  // 2147483647
constexpr int lower_limit = -pow(2, 31);     // -2147483648

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

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.reverse(0), 0);
  EXPECT_EQ(s.reverse(2147483642), 0);
  EXPECT_EQ(s.reverse(-2147483642), 0);
  EXPECT_EQ(s.reverse(2147447412), 2147447412);
  EXPECT_EQ(s.reverse(-2147447412), -2147447412);
  EXPECT_EQ(s.reverse(1234), 4321);
  EXPECT_EQ(s.reverse(-1234), -4321);
}
