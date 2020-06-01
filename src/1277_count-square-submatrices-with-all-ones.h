#include "base.h"

class Solution {
 public:
  int countSquares(const vector<vector<int>>& matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) {
      return 0;
    }

    auto height(matrix);  // height end with 1 width and end up with (i,j)
    int ret = 0;
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[0].size(); ++j) {
        if (matrix[i][j] == 0) {
          height[i][j] = 0;
        } else if (i == 0) {
          height[i][j] = 1;
        } else {
          height[i][j] = height[i - 1][j] + 1;
        }
      }
    }

    auto matrix_count(matrix);
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[0].size(); ++j) {
        if (matrix[i][j] == 0) {
          matrix_count[i][j] = 0;
        } else {
          int k = j;
          matrix_count[i][j] = 0;
          int min_height = height[i][j];
          int width = 1;
          while (k >= 0 && matrix[i][k] > 0) {
            min_height = min(min_height, height[i][k]);
            if (min_height >= width) {
              matrix_count[i][j] += 1;
              k--;
              width++;
            } else {
              break;
            }
          }
          ret += matrix_count[i][j];
        }
      }
    }

    cout << ret << endl;
    return ret;
  }
};
