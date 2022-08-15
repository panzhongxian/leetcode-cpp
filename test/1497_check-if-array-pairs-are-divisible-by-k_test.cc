#include "1497_check-if-array-pairs-are-divisible-by-k.h"

#include "base.h"

TEST(Solution, Demo) {
  Solution s;
  EXPECT_TRUE(s.canArrange({1, 2, 3, 4, 5, 10, 6, 7, 8, 9}, 5));
  EXPECT_TRUE(s.canArrange({1, 2, 3, 4, 5, 6}, 7));
  EXPECT_FALSE(s.canArrange({1, 2, 3, 4, 5, 6}, 10));
  EXPECT_FALSE(s.canArrange({-1, 1, -2, 2, -3, 3, -4, 4}, 3));
}
