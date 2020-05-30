#include "0201_bitwise-and-of-numbers-range.h"

int rangeBitwiseAnd(int m, int n) {
  int ret = m;
  for (size_t i = m + 1; i <= n; i++) {
    ret &= i;
  }
  return ret;
}

TEST(S, Demo) {
  Solution s;
#define CHECK(x, y) EXPECT_EQ(s.rangeBitwiseAnd(x, y), rangeBitwiseAnd(x, y))

  CHECK(5, 7);
  CHECK(0, 1);
  int base = 29123092;
  for (int i = 0; i < 10240; ++i) {
    CHECK(base, base + i);
  }
}
