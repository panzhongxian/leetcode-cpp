#include "base.h"
class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    vector<vector<int>>& unique_path(obstacleGrid);
    for (size_t i = 0; i < unique_path.size(); ++i) {
      for (size_t j = 0; j < unique_path[0].size(); ++j) {
        if (obstacleGrid[i][j] == 1) {
          unique_path[i][j] = 0;
          continue;
        }

        if (i == 0 && j == 0) {
          unique_path[i][j] = 1;
        } else if (i == 0) {
          unique_path[i][j] = (unique_path[i][j - 1] == 0) ? 0 : 1;
        } else if (j == 0) {
          unique_path[i][j] = (unique_path[i - 1][j] == 0) ? 0 : 1;
        } else {
          unique_path[i][j] = unique_path[i][j - 1] + unique_path[i - 1][j];
        }
      }
    }
    return unique_path.back().back();
  }
};
