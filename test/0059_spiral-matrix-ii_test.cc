#include "0059_spiral-matrix-ii.h"

#include "base.h"

TEST(S, Demo) {
  vector<vector<int>> expected_ret{{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
  Solution s;
  EXPECT_EQ(s.generateMatrix(3), expected_ret);
}
