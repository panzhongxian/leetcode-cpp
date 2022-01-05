#include "base.h"

class Solution {
 public:
  int findMin(vector<int>& nums) {
    return findSubArrayMin(nums, 0, nums.size() - 1);
  }
  int findSubArrayMin(vector<int>& nums, int left, int right) {
    int mid;
    while (true) {
      if (left == right) {
        return nums[left];
      }
      if (right - left == 1) {
        return min(nums[left], nums[right]);
      }

      if (nums[left] < nums[right]) {
        return nums[left];
      }

      // nums[left] >= nums[right]

      mid = (left + right) / 2;
      if (nums[mid] > nums[left]) {
        left = mid + 1;
      } else if (nums[mid] < nums[right]) {
        right = mid;
      } else {
        // nums[mid] <= nums[left] and nums[mid] >= nums[right] << condition
        // nums[mid] >= nums[left] or nums[mid] <= nums[right] << rotated sorted
        // nums[left] >= nums[right]
        // so: nums[left] == nums[mid] == nums[right]
        // If nums[mid] were the smallest one, the first index MAY be one of mid
        // and right.

        // method 1:
        // return min(findSubArrayMin(nums, left + 1, mid),
        //            findSubArrayMin(nums, mid + 1, right));
        // method 2:
        while (nums[left] == nums[mid] && left < mid) {
          left++;
        }
        while (nums[right] == nums[mid] && right > mid) {
          right--;
        }
      }
    }
  }
};
