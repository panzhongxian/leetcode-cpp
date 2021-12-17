#include "base.h"

class Solution {
 public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    if (mat.empty() || mat[0].size() * mat.size() != r * c) {
      return mat;
    }
    vector<vector<int>> ret(r, vector(c, 0));
    int m = 0;
    int n = 0;
    for (int i = 0; i < mat.size(); i++) {
      for (int j = 0; j < mat[0].size(); j++) {
        ret[m][n++] = mat[i][j];
        if (n == c) {
          n = 0;
          m++;
        }
      }
    }
    return ret;
  }
};
