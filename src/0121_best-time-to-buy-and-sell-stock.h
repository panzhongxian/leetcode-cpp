#include "base.h"
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1) {
      return 0;
    }
    int ret = 0;
    int pre_min = prices[0];
    for (auto i : prices) {
      if (pre_min > i) {
        pre_min = i;
      } else {
        ret = max(ret, i - pre_min);
      }
    }
    return ret;
  }
};
