class Solution {
public:
  int projectionArea(vector<vector<int>> &grid) {
    int n = grid.size();
    if (n == 0) {
      return 0;
    }

    int ret = 0;
    vector<int> back_max(n, 0);
    for (const auto &v : grid) {
      int max = 0;
      for (int i = 0; i < v.size(); i++) {
        int num = v[i];
        if (num != 0) {
          ret++;
        }
        if (max < num) {
          max = num;
        }
        if (back_max[i] < num) {
          back_max[i] = num;
        }
      }
      ret += max;
    }
    for (auto i : back_max) {
      ret += i;
    }
    return ret;
  }
};
