#include "base.h"
class Solution {
public:
  int smallestEqual(vector<int> &nums) {
    int i = 0;
    int j = 0;
    while (i < nums.size()) {
      if (nums[i++] == j++) {
        return i - 1;
      }
      if (j == 10) {
        j = 0;
      }
    }
    return -1;
  }
};
