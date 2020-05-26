#include "base.h"
class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> min_sum(grid);

    for (size_t i = 0; i < grid.size(); ++i) {
      for (size_t j = 0; j < grid[0].size(); ++j) {
        if (i == 0 && j == 0) {
          min_sum[i][j] = grid[0][0];
        } else if (i == 0) {
          min_sum[i][j] += min_sum[i][j - 1];
        } else if (j == 0) {
          min_sum[i][j] += min_sum[i - 1][j];
        } else {
          min_sum[i][j] += min(min_sum[i - 1][j], min_sum[i][j - 1]);
        }
      }
    }
    return min_sum.back().back();
  }
};
