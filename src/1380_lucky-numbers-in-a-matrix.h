class Solution {
 public:
  vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    vector<int> ret;
    set<pair<int, int>> min_num_locations;
    for (int i = 0; i < matrix.size(); i++) {
      int min_num = INT_MAX;
      int min_num_j;
      for (int j = 0; j < matrix[0].size(); j++) {
        if (matrix[i][j] < min_num) {
          min_num = matrix[i][j];
          min_num_j = j;
        }
      }
      min_num_locations.insert(pair<int, int>(i, min_num_j));
    }

    for (const auto& ij : min_num_locations) {
      if ([&matrix, &ij]() {
            for (int i = 0; i < matrix.size(); i++) {
              if (matrix[i][ij.second] > matrix[ij.first][ij.second]) {
                return false;
              }
            }
            return true;
          }()) {
        ret.push_back(matrix[ij.first][ij.second]);
      }
    }
    return ret;
  }
};
