#include "0079_word-search.h"

TEST(S, Demo) {
  vector<vector<char>> board = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};

  Solution s;
  EXPECT_EQ(s.exist(board, "ABCCED"), true);
  EXPECT_EQ(s.exist(board, "SEE"), true);
  EXPECT_EQ(s.exist(board, "ABCB"), false);
}
