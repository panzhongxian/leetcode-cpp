#include <climits>

#include "base.h"

class Solution {
 public:
  int getMinDistance(vector<int>& nums, int target, int start) {
    int ret = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == target) {
        int c = abs(i - start);
        if (c < ret) {
          ret = c;
        } else {
          return ret;
        }
      }
    }
    return ret;
  }
};
