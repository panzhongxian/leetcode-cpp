#include "base.h"

class Solution {
 public:
  inline int suface_of_one_colume(int height) {
    return height == 0 ? 0 : (4 * height + 2);
  }
  int surfaceArea(vector<vector<int>>& grid) {
    int ret = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid.size(); j++) {
        ret += suface_of_one_colume(grid[i][j]);
        if (i == 0 && j == 0) {
          continue;
        }
        if (i > 0) {
          ret -= min(grid[i - 1][j], grid[i][j]) << 1;
        }
        if (j > 0) {
          ret -= min(grid[i][j - 1], grid[i][j]) << 1;
        }
      }
    }
    return ret;
  }
};
