#include "base.h"

class Solution {
 public:
  void Spread(vector<vector<char>>& grid, int x, int y) {
    set<pair<int, int>> cur_step_idx_vec;
    set<pair<int, int>> next_step_idx_vec;

    cur_step_idx_vec.insert(pair<int, int>(x, y));

    while (cur_step_idx_vec.size()) {
      for (auto idx : cur_step_idx_vec) {
        grid[idx.first][idx.second] = '0';
        cout << "[" << idx.first << ", " << idx.second << "], ";
      }
      cout << endl;

      next_step_idx_vec.clear();
      int i, j;
      for (auto idx : cur_step_idx_vec) {
        i = idx.first;
        j = idx.second;
        if (i > 0) {
          if (grid[i - 1][j] == '1') {
            next_step_idx_vec.insert(pair<int, int>(i - 1, j));
          }
        }
        if (i + 1 < grid.size()) {
          if (grid[i + 1][j] == '1') {
            next_step_idx_vec.insert(pair<int, int>(i + 1, j));
          }
        }
        if (j > 0) {
          if (grid[i][j - 1] == '1') {
            next_step_idx_vec.insert(pair<int, int>(i, j - 1));
          }
        }
        if (j + 1 < grid[0].size()) {
          if (grid[i][j + 1] == '1') {
            next_step_idx_vec.insert(pair<int, int>(i, j + 1));
          }
        }
      }
      cur_step_idx_vec = move(next_step_idx_vec);
    }
  }
  int numIslands(vector<vector<char>>& grid) {
    int ret = 0;
    for (size_t i = 0; i < grid.size(); ++i) {
      for (size_t j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == '1') {
          Spread(grid, i, j);
          ret++;
        }
      }
    }
    return ret;
  }
};
