#include "0221_maximal-square.h"

TEST(S, Demo) {
  Solution s;

  vector<vector<char>> grid0({});
  EXPECT_EQ(s.maximalSquare(grid0), 0);

  vector<vector<char>> grid1({{}});
  EXPECT_EQ(s.maximalSquare(grid1), 0);

  vector<vector<char>> grid2({{'1', '1', '1', '1', '0'},
                              {'1', '1', '0', '1', '0'},
                              {'1', '1', '0', '0', '0'},
                              {'0', '0', '0', '0', '0'}});
  EXPECT_EQ(s.maximalSquare(grid2), 4);

  vector<vector<char>> grid3({{'1', '1', '0', '0', '0'},
                              {'1', '1', '0', '0', '0'},
                              {'0', '0', '1', '0', '0'},
                              {'0', '0', '0', '1', '1'}});
  EXPECT_EQ(s.maximalSquare(grid3), 4);

  vector<vector<char>> grid4({{'1', '0', '1', '0'},
                              {'1', '0', '1', '1'},
                              {'1', '0', '1', '1'},
                              {'1', '1', '1', '1'}});
  EXPECT_EQ(s.maximalSquare(grid4), 4);
}
