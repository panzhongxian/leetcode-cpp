class Solution {
 public:
  int countArrangement(int n) {
    int ret = 0;
    vector<vector<int>> vv(n + 1);
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j += i) {
        vv[i].push_back(1 << j);
        if (i != j) {
          vv[j].push_back(1 << i);
        }
      }
    }
    vector<int> remainings;
    vector<int> new_remainings;
    int k = 0;
    for (int i = 0; i < n; i++) {
      k = (k << 1) + 1;
    }
    remainings.push_back(k << 1);
    for (int i = 1; i <= n; i++) {
      for (int remaining : remainings) {
        for (int x : vv[i]) {
          if ((x & remaining) == 0) {
            continue;
          }
          new_remainings.push_back(x ^ remaining);
        }
      }
      remainings = move(new_remainings);
    }
    return remainings.size();
  }
};
