#include "0746_min-cost-climbing-stairs.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.minCostClimbingStairs({1, 100, 1, 1, 1, 100, 1, 1, 100, 1}), 6);
  EXPECT_EQ(s.minCostClimbingStairs({10, 15, 20}), 15);
}
