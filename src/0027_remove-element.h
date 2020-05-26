#include "base.h"
class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    if (nums.size() == 0) {
      return 0;
    }
    size_t i, j;
    i = 0;
    j = nums.size() - 1;
    while (i < j) {
      // find left val
      while (i < j && nums[i] != val) {
        i++;
      }
      // find right non-val
      while (i < j && nums[j] == val) {
        j--;
      }
      if (i < j) {
        nums[i++] = nums[j--];
      }
    }
    if (i == j) {
      return (nums[i] == val) ? i : i + 1;
    }
    return i;
  }
};
