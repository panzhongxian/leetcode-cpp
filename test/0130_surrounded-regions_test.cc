#include "0130_surrounded-regions.h"

TEST(S, Demo1) {
  vector<vector<char>> board = {{'O', 'O'}, {'O', 'O'}};
  Solution s;
  s.solve(board);
}

TEST(S, Demo2) {
  vector<vector<char>> board = {{'X', 'O', 'X', 'O', 'X', 'O'},
                                {'O', 'X', 'O', 'X', 'O', 'X'},
                                {'X', 'O', 'X', 'O', 'X', 'O'},
                                {'O', 'X', 'O', 'X', 'O', 'X'}};
  Solution s;
  s.solve(board);
}

TEST(S, Demo3) {
  vector<vector<char>> board = {};
  Solution s;
  s.solve(board);
}
