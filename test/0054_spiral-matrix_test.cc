#include "0054_spiral-matrix.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.spiralOrder({}), vector<int>({}));
  EXPECT_EQ(s.spiralOrder({{}}), vector<int>({}));
  EXPECT_EQ(s.spiralOrder({{1}}), vector<int>({1}));
  EXPECT_EQ(s.spiralOrder({{1}, {2}, {3}}), vector<int>({1, 2, 3}));

  EXPECT_EQ(s.spiralOrder({{1, 2, 3}}), vector<int>({1, 2, 3}));

  EXPECT_EQ(s.spiralOrder({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}),
            vector<int>({1, 2, 3, 6, 9, 8, 7, 4, 5}));
  EXPECT_EQ(s.spiralOrder({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}}),
            vector<int>({1, 2, 3, 6, 9, 12, 11, 10, 7, 4, 5, 8}));
}
