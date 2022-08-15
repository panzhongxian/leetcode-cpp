#include "1482_minimum-number-of-days-to-make-m-bouquets.h"

#include "base.h"
TEST(Solution, Demo) {
  Solution s;
  EXPECT_EQ(s.minDays({1, 10, 3, 10, 2}, 3, 1), 3);
  EXPECT_EQ(s.minDays({1, 10, 3, 10, 2}, 3, 2), -1);
  EXPECT_EQ(s.minDays({7, 7, 7, 7, 12, 7, 7}, 2, 3), 12);
}
