#include <climits>

#include "base.h"
class Solution {
 public:
  int maximumDifference(vector<int>& nums) {
    int ret = -1;
    int min = INT_MAX;
    for (int n : nums) {
      if (min < n) {
        ret = max(n - min, ret);
      } else {
        min = n;
      }
    }
    return ret;
  }
};
