#include "0077_combinations.h"

#include "base.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.combine(2, 2), vector<vector<int>>({{1, 2}}));
  EXPECT_EQ(s.combine(2, 1), vector<vector<int>>({{1}, {2}}));
  EXPECT_EQ(s.combine(2, 0), vector<vector<int>>({}));
}
