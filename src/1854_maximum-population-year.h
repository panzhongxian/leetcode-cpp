#include "base.h"

class Solution {
 public:
  int maximumPopulation(vector<vector<int>>& logs) {
    int m[100] = {0};
    for (auto& v : logs) {
      for (int i = v[0] - 1950; i < v[1] - 1950; i++) {
        m[i]++;
      }
    }
    int ret = -1;
    int max_population = INT_MIN;
    for (int i = 0; i < 100; i++) {
      if (m[i] > max_population) {
        ret = i;
        max_population = m[i];
      }
    }
    return 1950 + ret;
  }
};
