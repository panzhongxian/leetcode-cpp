#include "base.h"

class Solution {
 public:
  void SpreadBoarderO(vector<vector<char>>& board, int i, int j, char c) {
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
        board[i][j] != c) {
      return;
    }
    board[i][j] = 'O';
    SpreadBoarderO(board, i - 1, j, c);
    SpreadBoarderO(board, i + 1, j, c);
    SpreadBoarderO(board, i, j - 1, c);
    SpreadBoarderO(board, i, j + 1, c);
  }

  void solve(vector<vector<char>>& board) {
    if (board.size() == 0 || board[0].size() == 0) {
      return;
    }
    char replace_char = '1';
    for (int i = 0; i < (int)board.size(); ++i) {
      for (int j = 0; j < (int)board[0].size(); ++j) {
        if (board[i][j] == 'O') {
          board[i][j] = replace_char;
        }
      }
    }

    for (int i = 0; i < (int)board.size(); ++i) {
      SpreadBoarderO(board, i, 0, replace_char);
      SpreadBoarderO(board, i, board[0].size() - 1, replace_char);
    }
    for (int j = 0; j < (int)board[0].size(); ++j) {
      SpreadBoarderO(board, 0, j, replace_char);
      SpreadBoarderO(board, board.size() - 1, j, replace_char);
    }
    for (int i = 0; i < (int)board.size(); ++i) {
      for (int j = 0; j < (int)board[0].size(); ++j) {
        if (board[i][j] == replace_char) {
          cout << i << ":" << j << endl;
          board[i][j] = 'X';
        }
      }
    }
  }
};
