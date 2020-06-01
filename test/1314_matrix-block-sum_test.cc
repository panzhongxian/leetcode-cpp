#include "1314_matrix-block-sum.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.matrixBlockSum({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 1),
            vector<vector<int>>({{12, 21, 16}, {27, 45, 33}, {24, 39, 28}}));
  EXPECT_EQ(s.matrixBlockSum({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 2),
            vector<vector<int>>({{45, 45, 45}, {45, 45, 45}, {45, 45, 45}}));
}
