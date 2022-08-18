#include <array>
#include <vector>
using namespace std;
class Solution {
 public:
  int CheckMaxSquare(vector<vector<array<int, 4>>>& continuous_ones, int i,
                     int j, int start) {
    int ret = 0;
    int end = min(continuous_ones[i][j][0], continuous_ones[i][j][1]);
    for (int k = start; k < end; k++) {
      if (continuous_ones[i][j][0] > k && continuous_ones[i][j][1] > k &&
          continuous_ones[i - k][j - k][2] > k &&
          continuous_ones[i - k][j - k][3] > k) {
        ret = k + 1;
      }
    }
    return ret;
  }

  int largest1BorderedSquare(const vector<vector<int>>& grid) {
    vector<vector<array<int, 4>>> continuous_ones(
        grid.size(),
        vector<array<int, 4>>(grid[0].size(), array<int, 4>({0, 0, 0, 0})));
    int l1 = grid.size();
    int l2 = grid[0].size();
    // up, right, down, left;
    //  0,     3,    2,    1;
    int i, j, m, n;
    for (i = 0; i < grid.size(); i++) {
      for (j = 0; j < grid[0].size(); j++) {
        m = l1 - i - 1;
        n = l2 - j - 1;

        continuous_ones[i][j][0] =
            !grid[i][j] ? 0 : (i == 0 ? 1 : continuous_ones[i - 1][j][0] + 1);
        continuous_ones[i][j][1] =
            !grid[i][j] ? 0 : (j == 0 ? 1 : continuous_ones[i][j - 1][1] + 1);
        continuous_ones[m][j][2] =
            !grid[m][j] ? 0
                        : (m + 1 == l1 ? 1 : continuous_ones[m + 1][j][2] + 1);
        continuous_ones[i][n][3] =
            !grid[i][n] ? 0
                        : (n + 1 == l2 ? 1 : continuous_ones[i][n + 1][3] + 1);
      }
    }
    int ret = 0;
    for (i = 0; i < grid.size(); i++) {
      for (j = 0; j < grid[0].size(); j++) {
        if (continuous_ones[i][j][0] <= ret ||
            continuous_ones[i][j][1] <= ret) {
          continue;
        }
        ret = max(ret, CheckMaxSquare(continuous_ones, i, j, ret));
      }
    }
    return ret * ret;
  }
};
