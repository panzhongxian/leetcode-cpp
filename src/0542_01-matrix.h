class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    vector<vector<int>> ret(mat.size(), vector<int>(mat[0].size(), INT_MAX));
    vector<vector<int>> same_distance_index, new_same_distance_index;
    int i, j;
    int counter = 0;
    for (i = 0; i < mat.size(); i++) {
      for (j = 0; j < mat[0].size(); j++) {
        if (mat[i][j] == 0) {
          same_distance_index.push_back(vector<int>{i, j});
          ret[i][j] = 0;
          counter++;
        }
      }
    }
    int distance = 0;
    int new_distance = 1;
    while (counter < mat.size() * mat[0].size()) {
      for (auto& ij : same_distance_index) {
        i = ij[0];
        j = ij[1];
        ret[i][j] = distance;
        if (i > 0 && ret[i - 1][j] > new_distance) {
          new_same_distance_index.push_back(vector<int>{i - 1, j});
          ret[i - 1][j] = new_distance;
          counter++;
        }
        if (j > 0 && ret[i][j - 1] > new_distance) {
          new_same_distance_index.push_back(vector<int>{i, j - 1});
          ret[i][j - 1] = new_distance;
          counter++;
        }
        if (i + 1 < ret.size() && ret[i + 1][j] > new_distance) {
          new_same_distance_index.push_back(vector<int>{i + 1, j});
          ret[i + 1][j] = new_distance;
          counter++;
        }
        if (j + 1 < ret[0].size() && ret[i][j + 1] > new_distance) {
          new_same_distance_index.push_back(vector<int>{i, j + 1});
          ret[i][j + 1] = new_distance;
          counter++;
        }
      }
      same_distance_index = move(new_same_distance_index);
      distance++;
      new_distance++;
    }
    return ret;
  }
};
