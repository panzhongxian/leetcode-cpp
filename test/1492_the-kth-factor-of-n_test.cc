#include "1492_the-kth-factor-of-n.h"

#include "base.h"

TEST(Solution, Demo) {
  Solution s;
  EXPECT_EQ(s.kthFactor(12, 1), 1);
  EXPECT_EQ(s.kthFactor(12, 3), 3);
  EXPECT_EQ(s.kthFactor(12, 6), 12);
  EXPECT_EQ(s.kthFactor(12, 7), -1);
  EXPECT_EQ(s.kthFactor(1, 1), 1);
  EXPECT_EQ(s.kthFactor(1, 2), -1);
}
