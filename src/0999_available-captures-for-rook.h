#include "base.h"

class Solution {
 public:
  auto check_pawn(vector<vector<char>> vv, int x, int y) {
    return pair<bool, int>{vv[x][y] != '.', vv[x][y] == 'p'};
  }
  int numRookCaptures(vector<vector<char>>& board) {
    int r_pos_x, r_pos_y;
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board.size(); j++) {
        if (board[i][j] == 'R') {
          r_pos_x = i;
          r_pos_y = j;
          break;
        }
      }
    }
    int ret = 0;
    for (int i = r_pos_x - 1; i >= 0; i--) {
      if (auto [break_flag, c] = check_pawn(board, i, r_pos_y); break_flag) {
        ret += c;
        break;
      }
    }

    for (int i = r_pos_y - 1; i >= 0; i--) {
      if (auto [break_flag, c] = check_pawn(board, r_pos_x, i); break_flag) {
        ret += c;
        break;
      }
    }

    for (int i = r_pos_x + 1; i < board.size(); i++) {
      if (auto [break_flag, c] = check_pawn(board, i, r_pos_y); break_flag) {
        ret += c;
        break;
      }
    }

    for (int i = r_pos_y + 1; i < board[0].size(); i++) {
      if (auto [break_flag, c] = check_pawn(board, r_pos_x, i); break_flag) {
        ret += c;
        break;
      }
    }
    return ret;
  }
};
