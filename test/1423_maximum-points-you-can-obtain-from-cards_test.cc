#include "1423_maximum-points-you-can-obtain-from-cards.h"

#include "base.h"

TEST(Solution, Demo) {
  Solution s;
  EXPECT_EQ(s.maxScore({1, 2, 3, 4, 5, 6, 1}, 3), 12);
  EXPECT_EQ(s.maxScore({2, 2, 2}, 2), 4);
  EXPECT_EQ(s.maxScore({9, 7, 7, 9, 7, 7, 9}, 7), 55);
}
