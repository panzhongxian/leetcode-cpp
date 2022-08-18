#include "1139_largest-1-bordered-square.h"

#include "base.h"

TEST(Solution, Demo) {
  Solution s;
  EXPECT_EQ(s.largest1BorderedSquare({{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}), 9);
}
