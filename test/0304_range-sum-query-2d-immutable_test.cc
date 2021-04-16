#include "0304_range-sum-query-2d-immutable.h"

TEST(S, Demo) {
  vector<vector<int>> vec{{3, 0, 1, 4, 2},
                          {5, 6, 3, 2, 1},
                          {1, 2, 0, 1, 5},
                          {4, 1, 0, 1, 7},
                          {1, 0, 3, 0, 5}};

  NumMatrix s(vec);
  EXPECT_EQ(s.sumRegion(2, 1, 4, 3), 8);
  EXPECT_EQ(s.sumRegion(1, 1, 2, 2), 11);
  EXPECT_EQ(s.sumRegion(1, 2, 2, 4), 12);
}
