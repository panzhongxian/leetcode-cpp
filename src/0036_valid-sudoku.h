#include "base.h"

class Solution {
 public:
  bool isValidSudoku(const vector<vector<char>>& board) {
    if (board.size() != 9 || (board.size() > 0 && board[0].size() != 9)) {
      return false;
    }
#define CHECK_VALUE_IN_SET(s, i, j) \
  char c = board[i][j];             \
  if (c == '.') {                   \
    continue;                       \
  }                                 \
  if (s.count(c) > 0) {             \
    return false;                   \
  }                                 \
  s.insert(c);

    for (size_t i = 0; i < 9; ++i) {
      unordered_set<int> s;
      for (size_t j = 0; j < 9; ++j) {
        CHECK_VALUE_IN_SET(s, i, j);
      }
    }

    for (size_t i = 0; i < 9; ++i) {
      unordered_set<int> s;
      for (size_t j = 0; j < 9; ++j) {
        CHECK_VALUE_IN_SET(s, j, i);
      }
    }
    for (size_t i = 0; i < 3; ++i) {
      for (size_t j = 0; j < 3; ++j) {
        unordered_set<int> s;
        for (size_t m = 0; m < 3; ++m) {
          for (size_t n = 0; n < 3; ++n) {
            CHECK_VALUE_IN_SET(s, (i * 3 + m), (j * 3 + n));
          }
        }
      }
    }
    return true;
  }
};
