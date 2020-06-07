#include "0069_sqrtx.h"

TEST(S, Demo) {
  Solution s;
  for (int i = 0; i < 10000000; ++i) {
    int ret = s.mySqrt(i);
    EXPECT_LE(ret * ret, i);
    EXPECT_GT((ret + 1) * (ret + 1), i);
  }
}
