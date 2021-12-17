class Solution {
 public:
  vector<vector<int>> imageSmoother(vector<vector<int>> &img) {
    vector<vector<int>> ret(img);
    int bottom_limit = img.size() - 1;
    int right_limit = img[0].size() - 1;

    for (int i = 0; i <= bottom_limit; i++) {
      for (int j = 0; j <= right_limit; j++) {
        int sum = 0;
        int cnt = 0;
        for (int m = max(i - 1, 0); m <= min(bottom_limit, i + 1); m++) {
          for (int n = max(j - 1, 0); n <= min(right_limit, j + 1); n++) {
            sum += img[m][n];
            cnt++;
          }
        }
        ret[i][j] = sum / cnt;
      }
    }
    return ret;
  }
};
