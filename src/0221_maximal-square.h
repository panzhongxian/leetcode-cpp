#include "base.h"

class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.size() == 0) {
      return 0;
    }
    if (matrix[0].size() == 0) {
      return 0;
    }

    int max_length = 0;
    vector<vector<int>> max_square_length(matrix.size(),
                                          vector<int>(matrix[0].size()));

    for (size_t i = 0; i < matrix.size(); ++i) {
      for (size_t j = 0; j < matrix[0].size(); ++j) {
        if (matrix[i][j] == '0') {
          max_square_length[i][j] = 0;
          continue;
        }

        if (i == 0) {
          max_square_length[i][j] = 1;
          max_length = max(max_length, 1);
          continue;
        }

        if (j == 0) {
          max_square_length[i][j] = 1;
          max_length = max(max_length, 1);
          continue;
        }

        int pre_square_length = max_square_length[i - 1][j - 1];
        if (pre_square_length == 0) {
          max_square_length[i][j] = 1;
          max_length = max(max_length, 1);
          continue;
        }

        max_square_length[i][j] = max_square_length[i - 1][j - 1] + 1;
        for (size_t x = 0; x < pre_square_length; x++) {
          if (matrix[i][j - 1 - x] == '0' || matrix[i - 1 - x][j] == '0') {
            max_square_length[i][j] = x + 1;
            break;
          }
        }
        max_length = max(max_length, max_square_length[i][j]);
      }
    }
    return max_length * max_length;
  }
};
