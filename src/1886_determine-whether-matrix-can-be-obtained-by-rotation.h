#include "base.h"

class Solution {
 public:
  typedef function<int(int, int, int)> rotate_index_func;
  bool is_rotated(vector<vector<int>>& mat, vector<vector<int>>& target,
                  rotate_index_func rotate_i_func,
                  rotate_index_func rotate_j_func) {
    for (int i = 0; i < mat.size(); i++) {
      for (int j = 0; j < mat.size(); j++) {
        if (mat[i][j] != target[rotate_i_func(i, j, mat.size())]
                               [rotate_j_func(i, j, mat.size())]) {
          return false;
        }
      }
    }
    return true;
  }

  bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    return mat == target ||
           is_rotated(
               mat, target, [](int, int j, int) { return j; },
               [](int i, int, int n) { return n - i - 1; }) ||
           is_rotated(
               mat, target, [](int i, int, int n) { return n - i - 1; },
               [](int, int j, int n) { return n - j - 1; }) ||
           is_rotated(
               mat, target, [](int, int j, int n) { return n - j - 1; },
               [](int i, int, int) { return i; });
  }
};
