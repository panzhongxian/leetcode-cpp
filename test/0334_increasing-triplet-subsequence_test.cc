#include "0334_increasing-triplet-subsequence.h"

#include "base.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.increasingTriplet({1, 2, 3, 4, 5}), true);
  EXPECT_EQ(s.increasingTriplet({1, 4, 3, 2, 5}), true);
  EXPECT_EQ(s.increasingTriplet({5, 4, 3, 2, 1}), false);
  EXPECT_EQ(s.increasingTriplet({2, 1, 5, 0, 4, 6}), true);
}
