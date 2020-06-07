#include "0581_shortest-unsorted-continuous-subarray.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.findUnsortedSubarray({2, 6, 4, 8, 10, 9, 15}), 5);
}
