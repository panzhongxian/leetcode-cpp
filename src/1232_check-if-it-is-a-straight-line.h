#include "base.h"

class Solution {
 public:
  bool checkStraightLine(vector<vector<int>>& coordinates) {
    int x1_diff = coordinates[1][0] - coordinates[0][0];
    int y1_diff = coordinates[1][1] - coordinates[0][1];
    int x2_diff, y2_diff;
    for (int i = 2; i < coordinates.size(); i++) {
      x2_diff = coordinates[i][0] - coordinates[0][0];
      y2_diff = coordinates[i][1] - coordinates[0][1];
      if (y2_diff * x1_diff != y1_diff * x2_diff) {
        return false;
      }
    }
    return true;
  }
};
