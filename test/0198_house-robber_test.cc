#include "0198_house-robber.h"
TEST(S, Demo) {
  Solution s;

  EXPECT_EQ(s.rob({1, 2, 3, 1}), 4);
  EXPECT_EQ(s.rob({2, 7, 9, 3, 1}), 12);
  EXPECT_EQ(s.rob({9, 8, 8, 9}), 18);
}
