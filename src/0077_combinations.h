#include <vector>

using std::vector;

class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ret;
    if (k > n || k == 0) {
      return ret;
    }
    if (k == 1) {
      for (int i = 1; i <= n; i++) {
        ret.push_back(vector<int>({i}));
      }
      return ret;
    }
    if (k == n) {
      vector<int> line{};

      for (int i = 1; i <= n; i++) {
        line.push_back(i);
      }
      ret.push_back(line);
      return ret;
    }

    for (int i = 1; i <= n; i++) {
      auto lines = combine(i - 1, k - 1);
      for (auto& line : lines) {
        line.push_back(i);
        ret.push_back(line);
      }
    }

    return ret;
  }
};
