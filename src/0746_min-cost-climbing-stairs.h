#include "base.h"
class Solution {
 public:
  int minCostClimbingStairs(const vector<int>& cost) {
    if (cost.size() < 2) {
      return 0;
    }

    vector<int> min_cost(cost.size());
    min_cost[0] = cost[0];
    min_cost[1] = cost[1];
    for (size_t i = 2; i < cost.size(); ++i) {
      min_cost[i] = min(min_cost[i - 1], min_cost[i - 2]) + cost[i];
    }
    return min(min_cost[cost.size() - 1], min_cost[cost.size() - 2]);
  }
};
