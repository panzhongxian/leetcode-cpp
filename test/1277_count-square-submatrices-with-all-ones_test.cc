#include "1277_count-square-submatrices-with-all-ones.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.countSquares({{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}}), 15);
  EXPECT_EQ(s.countSquares({{1, 0, 1}, {1, 1, 0}, {1, 1, 0}}), 7);
}
