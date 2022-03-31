class Solution {
 public:
  int minSteps(int n) {
    vector<int> v(n + 1, INT_MAX);
    v[1] = 0;
    for (int i = 1; i <= n; i++) {
      int k = v[i];
      for (int j = i; j <= n; j += i) {
        v[j] = min(1 + k++, v[j]);  // 1 for copy
      }
    }

    return v[n];
  }
};
