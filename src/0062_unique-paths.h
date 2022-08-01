#include "base.h"

class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<int> paths(m, 1), new_paths(m);
    for (int i = 1; i < n; i++) {
      new_paths[0] = 1;
      for (int j = 1; j < m; j++) {
        new_paths[j] = new_paths[j - 1] + paths[j];
      }
      paths.swap(new_paths);
    }
    return paths[m - 1];
  }
};
