#include "base.h"

class Solution {
 public:
  int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    int mid;
    while (true) {
      if (nums[left] <= nums[right]) {
        return nums[left];
      }

      if (right - left == 1) {
        return nums[right];
      }

      mid = (left + right) / 2;
      if (nums[mid] > nums[left]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
  }
};
