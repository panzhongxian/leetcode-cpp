#include "1360_number-of-days-between-two-dates.h"

TEST(Solution, Demo) {
  Solution s;
  EXPECT_EQ(s.daysBetweenDates("2020-12-01", "2021-12-01"), 365);
  EXPECT_EQ(s.daysBetweenDates("2019-12-01", "2021-12-01"), 365 * 2 + 1);
}
