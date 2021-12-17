#include "1742_maximum-number-of-balls-in-a-box.h"

#include "base.h"

TEST(Solution, Demo) {
  Solution s;
  EXPECT_EQ(s.countBalls(1, 10), 2);
  EXPECT_EQ(s.countBalls(19, 28), 2);
}
