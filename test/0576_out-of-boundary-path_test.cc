#include "0576_out-of-boundary-path.h"

#include "base.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.findPaths(1, 3, 5, 0, 1), 32);
  EXPECT_EQ(s.findPaths(2, 2, 2, 0, 0), 6);
  EXPECT_EQ(s.findPaths(3, 3, 20, 0, 1), 766958445);
  EXPECT_EQ(s.findPaths(3, 3, 21, 0, 1), 840700262);
  EXPECT_EQ(s.findPaths(8, 50, 20, 5, 26), 249465772);
  EXPECT_EQ(s.findPaths(8, 50, 23, 5, 26), 914783380);
}
