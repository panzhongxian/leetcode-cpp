#include "0342_power-of-four.h"

#include "base.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.isPowerOfFour(-1), false);
  EXPECT_EQ(s.isPowerOfFour(0), false);
  EXPECT_EQ(s.isPowerOfFour(1), true);
  EXPECT_EQ(s.isPowerOfFour(2), false);
  EXPECT_EQ(s.isPowerOfFour(3), false);
  EXPECT_EQ(s.isPowerOfFour(4), true);
  EXPECT_EQ(s.isPowerOfFour(12), false);
  EXPECT_EQ(s.isPowerOfFour(16), true);
}
