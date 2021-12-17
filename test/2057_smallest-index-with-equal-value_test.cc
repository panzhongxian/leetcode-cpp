#include "2057_smallest-index-with-equal-value.h"

TEST(Solution, Demo) {
  vector<int> v{7, 8, 3, 5, 2, 6, 3, 1, 1, 4, 5, 4,
                8, 7, 2, 0, 9, 9, 0, 5, 7, 1, 6};
  Solution s;
  EXPECT_EQ(s.smallestEqual(v), 21);
}
