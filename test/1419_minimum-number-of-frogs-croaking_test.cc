#include "1419_minimum-number-of-frogs-croaking.h"

#include "base.h"

TEST(Solution, Demo) {
  Solution s;
  EXPECT_EQ(s.minNumberOfFrogs("croakcroak"), 1);
  EXPECT_EQ(s.minNumberOfFrogs("crcoakroak"), 2);
  EXPECT_EQ(s.minNumberOfFrogs("croakcrook"), -1);
  EXPECT_EQ(s.minNumberOfFrogs("croakcroa"), -1);
}
