#include "base.h"

class Solution {
 public:
  int diagonalSum(vector<vector<int>>& mat) {
    int upper_limit = mat.size() >> 1;
    int ret = 0;
    for (int i = 0; i < upper_limit; i++) {
      ret += mat[i][i] + mat[i][mat.size() - i - 1] +
             mat[mat.size() - i - 1][i] +
             mat[mat.size() - i - 1][mat.size() - i - 1];
    }
    if (mat.size() & 1) {
      ret += mat[upper_limit][upper_limit];
    }
    return ret;
  }
};
