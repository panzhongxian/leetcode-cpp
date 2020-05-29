#include "base.h"

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    size_t p0 = 0;
    size_t p2 = nums.size();
    size_t p1;

    while (p0 < p2) {
      p1 = (p0 + p2) / 2;

      if (nums[p1] == target) {
        return p1;
      }

      if (nums[p1] > target) {
        p2 = p1;
      } else if (p0 == p1) {
        break;
      } else {
        p0 = p1;
      }
    }
    return nums[p0] > target ? p0 : p0 + 1;
  }
};
