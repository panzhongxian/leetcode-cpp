class Solution {
 public:
  vector<vector<int>> transpose(vector<vector<int>> &matrix) {
    vector<vector<int>> ret;
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        if (i == 0) {
          ret.push_back(vector<int>{matrix[i][j]});
        } else {
          ret[j].push_back(matrix[i][j]);
        }
      }
    }
    return ret;
  }
};
