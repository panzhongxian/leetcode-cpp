class Solution {
public:
  int countNegatives(vector<vector<int>> &grid) {
    int ret = 0;
    int i = 0;
    int j = grid[0].size() - 1;

    for (int i = 0; i < grid.size(); i++) {
      while (j >= 0 && grid[i][j] < 0) {
        j--;
      }
      ret += grid[0].size() - j - 1;
    }
    return ret;
  }
};
