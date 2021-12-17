class Solution {
 public:
  bool isCovered(vector<vector<int>> &ranges, int left, int right) {
    sort(ranges.begin(), ranges.end());
    for (auto &v : ranges) {
    }
    for (auto &v : ranges) {
      if (left >= v[0] && v[1] + 1 > left) {
        left = v[1] + 1;
      }
      if (right <= v[1] && v[0] - 1 < right) {
        right = v[0] - 1;
      }
      if (left > right) {
        return true;
      }
    }
    return false;
  }
};
