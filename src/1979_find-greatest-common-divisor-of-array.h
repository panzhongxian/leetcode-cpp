#include <climits>

#include "base.h"

class Solution {
 public:
  int findGCD(vector<int>& nums) {
    int min = INT_MAX;
    int max = INT_MIN;
    for (int num : nums) {
      if (num > max) {
        max = num;
      }
      if (num < min) {
        min = num;
      }
    }
    if (max % min == 0) {
      return min;
    }
    int ret = 1;
    for (int i = 2; i < min; i++) {
      if (min % i == 0 && max % i == 0) {
        ret = i;
      }
    }
    return ret;
  }
};
