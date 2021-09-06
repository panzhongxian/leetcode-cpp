#include "0240_search-a-2d-matrix-ii.h"

#include "base.h"

TEST(S, Demo1) {
  vector<vector<int>> matrix{{1, 4, 7, 11, 15},
                             {2, 5, 8, 12, 19},
                             {3, 6, 9, 16, 22},
                             {10, 13, 14, 17, 24},
                             {18, 21, 23, 26, 30}};
  Solution s;
  EXPECT_EQ(s.searchMatrix(matrix, 5), true);
}

TEST(S, Demo2) {
  vector<vector<int>> matrix{{1, 4, 7, 11, 15},
                             {2, 5, 8, 12, 19},
                             {3, 6, 9, 16, 22},
                             {10, 13, 14, 17, 24},
                             {18, 21, 23, 26, 30}};
  Solution s;
  EXPECT_EQ(s.searchMatrix(matrix, 20), false);
}
