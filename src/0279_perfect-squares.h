#include <climits>
class Solution {
 public:
  int numSquares(int n) {
    vector<int> v(n + 1, 0);
    int k = 1;
    for (int i = 1; i <= n; i++) {
      if (k * k == i) {
        v[i] = 1;
        k++;
        continue;
      }
      int min_val = INT_MAX;
      for (int j = 1; j < k; j++) {
        min_val = min(min_val, v[i - j * j] + 1);
      }
      v[i] = min_val;
    }
    return v[n];
  }
};
