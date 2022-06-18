class Solution {
 public:
  vector<vector<int>> combinationSum3(int k, int n, int start = 1) {
    vector<vector<int>> ret;
    if (k > 10 - start || n < start) {
      return ret;
    }
    if (n == 0 && k == 0) {
      return vector<vector<int>>{vector<int>()};
    } else if (n == start && k == 1) {
      return vector<vector<int>>{vector<int>{start}};
    }
    for (int i = start; i < 10; i++) {
      cout << "combinationSum3(" << (k - 1) << ", " << (n - i) << ", " << i + 1
           << ");" << endl;
      for (auto x : combinationSum3(k - 1, n - i, i + 1)) {
        v.insert(v.begin(), start);
        ret.push_back(v);
      }
    }
    return ret;
  }
};
