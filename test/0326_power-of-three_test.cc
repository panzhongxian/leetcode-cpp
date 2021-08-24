#include "0326_power-of-three.h"

#include "base.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.isPowerOfThree(-1), false);
  EXPECT_EQ(s.isPowerOfThree(0), false);
  EXPECT_EQ(s.isPowerOfThree(1), true);
  EXPECT_EQ(s.isPowerOfThree(2), false);
  EXPECT_EQ(s.isPowerOfThree(3), true);
  EXPECT_EQ(s.isPowerOfThree(45), false);
  EXPECT_EQ(s.isPowerOfThree(27), true);
}
