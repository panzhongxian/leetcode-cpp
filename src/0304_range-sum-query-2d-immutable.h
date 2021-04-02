#include "base.h"

class NumMatrix {
 public:
  NumMatrix(vector<vector<int>> &matrix) : empty_vector_flag(false) {
    int m = matrix.size();
    if (m == 0) {
      empty_vector_flag = true;
      return;
    }
    int n = matrix[0].size();
    if (n == 0) {
      empty_vector_flag = true;
      return;
    }
    sum_matrix = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        sum_matrix[i][j] = sum_matrix[i - 1][j] + sum_matrix[i][j - 1] -
                           sum_matrix[i - 1][j - 1] + matrix[i - 1][j - 1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return sum_matrix[row2 + 1][col2 + 1] + sum_matrix[row1][col1] -
           sum_matrix[row2 + 1][col1] - sum_matrix[row1][col2 + 1];
  }

 private:
  vector<vector<int>> sum_matrix;
  int empty_vector_flag;
};
