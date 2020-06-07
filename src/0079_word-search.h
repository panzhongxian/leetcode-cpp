#include "base.h"

class Solution {
  string word;

 public:
  bool SearchFromPoint(vector<vector<char>>& board, int i, int j,
                       int char_index) {
    if (char_index == (int)word.length()) {
      return true;
    }

    if (i < 0 || i >= (int)board.size() || j < 0 || j >= (int)board[0].size() ||
        board[i][j] != word[char_index]) {
      return false;
    }

    board[i][j] = ' ';
    bool ret = SearchFromPoint(board, i - 1, j, char_index + 1) ||
               SearchFromPoint(board, i, j - 1, char_index + 1) ||
               SearchFromPoint(board, i + 1, j, char_index + 1) ||
               SearchFromPoint(board, i, j + 1, char_index + 1);
    board[i][j] = word[char_index];
    return ret;
  }

  bool exist(vector<vector<char>>& board, string word) {
    this->word = word;
    for (int i = 0; i < (int)board.size(); ++i) {
      for (int j = 0; j < (int)board[0].size(); ++j) {
        if (SearchFromPoint(board, i, j, 0)) {
          return true;
        }
      }
    }
    return false;
  }
};
