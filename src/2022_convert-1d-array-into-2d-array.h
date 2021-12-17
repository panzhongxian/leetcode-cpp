class Solution {
 public:
  vector<vector<int>> construct2DArray(vector<int> &original, int m, int n) {
    vector<vector<int>> ret;
    if (original.size() != m * n) {
      return ret;
    }
    for (int start = 0; start < original.size(); start += n) {
      ret.push_back(
          vector<int>(original.begin() + start, original.begin() + start + n));
    }
    return ret;
  }
};
~
