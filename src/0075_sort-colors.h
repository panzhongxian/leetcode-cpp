#include "base.h"

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int i, j, k;
    i = 0;
    j = nums.size() - 1;
    k = 0;
    while (i <= j && k <= j) {
      if (nums[k] == 2) {
        swap(nums[k], nums[j--]);
      } else if (nums[k] == 0) {
        if (k == i) {
          k++;
          i++;
        } else {
          swap(nums[k], nums[i++]);
        }
      } else {
        k++;
      }
    }
  }
};
