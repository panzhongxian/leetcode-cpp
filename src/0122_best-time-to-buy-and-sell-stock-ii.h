#include "base.h"

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() < 2) {
      return 0;
    }

    int ret = 0;
    int pre_min = prices[0];
    int pre_max = prices[0];
    for (size_t i = 1; i < prices.size(); ++i) {
      if (prices[i] >= prices[i - 1]) {
        ret += prices[i] - prices[i - 1];
      }
    }
    return ret;
  }
};
