#include <vector>
class Solution {
 public:
  int numSubmat(vector<vector<int>>& mat) {
    vector<vector<int>> column_height(mat.size(), vector<int>(mat[0].size()));
    for (int i = 0; i < mat.size(); i++) {
      for (int j = 0; j < mat[0].size(); j++) {
        if (i == 0) {
          column_height[i][j] = mat[i][j];
        } else if (mat[i][j] == 0) {
          column_height[i][j] = 0;
        } else {
          column_height[i][j] = column_height[i - 1][j] + 1;
        }
      }
    }
    int ret = 0;
    for (int i = 0; i < mat.size(); i++) {
      for (int j = 0; j < mat[0].size(); j++) {
        if (column_height[i][j] == 0) {
          continue;
        }
        int min_height = column_height[i][j];
        for (int n = j; n >= 0; n--) {
          min_height = min(column_height[i][n], min_height);
          if (min_height == 0) {
            break;
          }
          ret += min_height;
        }
      }
    }
    return ret;
  }
};
