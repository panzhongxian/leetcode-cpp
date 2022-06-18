class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int m = 0;
    int n = 0;
    int direction = 0;  // 0: up, 1: down
    vector<int> ret(mat.size() * mat[0].size());

    for (int i = 0; i < ret.size(); i++) {
      ret[i] = mat[m][n];
      if (direction == 0) {
        if (n == mat[0].size() - 1) {
          m++;
          direction = 1;
        } else if (m == 0) {
          n++;
          direction = 1;
        } else {
          m--;
          n++;
        }
      } else {
        if (m == mat.size() - 1) {
          n++;
          direction = 0;
        } else if (n == 0) {
          m++;
          direction = 0;
        } else {
          m++;
          n--;
        }
      }
    }
    return ret;
  }
};
