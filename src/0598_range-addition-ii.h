#include "base.h"

class Solution {
 public:
  int maxCount(int m, int n, vector<vector<int>>& ops) {
    if (ops.empty()) return m * n;
    int min_x = ops[0][0];
    int min_y = ops[0][1];
    for (int i = 1; i < ops.size(); i++) {
      if (ops[i][0] < min_x) {
        min_x = ops[i][0];
      }
      if (ops[i][1] < min_y) {
        min_y = ops[i][1];
      }
    }
    return min_x * min_y;
  }
};
