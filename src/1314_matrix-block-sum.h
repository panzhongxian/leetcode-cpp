#include "base.h"

class Solution {
 public:
  vector<vector<int>> matrixBlockSum(const vector<vector<int>>& mat, int K) {
    if (mat.size() == 0 || mat[0].size() == 0 || K == 0) {
      return mat;
    }

    int row_limit = mat.size();
    int col_limit = mat[0].size();

    auto v_sum(mat);
    for (int i = 0; i < row_limit; ++i) {
      for (int j = 0; j < col_limit; ++j) {
        if (i == 0) {
          v_sum[i][j] = 0;
          for (int k = 0; k < min(row_limit, K + 1); ++k) {
            v_sum[i][j] += mat[k][j];
          }
          continue;
        }

        v_sum[i][j] = v_sum[i - 1][j];
        if (i - K - 1 >= 0) {
          v_sum[i][j] -= mat[i - K - 1][j];
        }
        if (i + K < row_limit) {
          v_sum[i][j] += mat[i + K][j];
        }
      }
    }

    auto ret(mat);
    for (int i = 0; i < row_limit; ++i) {
      for (int j = 0; j < col_limit; ++j) {
        if (j == 0) {
          ret[i][j] = 0;
          for (int k = 0; k < min(col_limit, K + 1); ++k) {
            ret[i][j] += v_sum[i][k];
          }
          continue;
        }

        ret[i][j] = ret[i][j - 1];
        if (j - K - 1 >= 0) {
          ret[i][j] -= v_sum[i][j - K - 1];
        }
        if (j + K < col_limit) {
          ret[i][j] += v_sum[i][j + K];
        }
      }
    }

    return ret;
  }
};
