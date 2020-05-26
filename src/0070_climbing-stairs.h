#include "base.h"
class Solution {
 public:
  int climbStairs(int n) {
    if (n == 1) {
      return 1;
    }
    if (n == 2) {
      return 2;
    }

    vector<int> climb_ways(n + 1);
    climb_ways[0] = 1;
    climb_ways[1] = 1;
    for (size_t i = 2; i <= n; ++i) {
      climb_ways[i] = climb_ways[i - 1] + climb_ways[i - 2];
    }

    return climb_ways.back();
  }
};
