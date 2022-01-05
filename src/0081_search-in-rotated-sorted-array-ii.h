#include "base.h"

class Solution {
 private:
  int min_value_index;

 public:
  bool search(vector<int>& nums, int target) {
    if (nums.size() == 0) {
      return false;
    }
    findMinIndex(nums);
    int left = 0;
    int right = nums.size();
    int mid, mid_val;
    while (left < right) {
      mid = (left + right) / 2;
      mid_val = nums[(mid + min_value_index) % nums.size()];
      if (mid_val == target) {
        return true;
      }
      if (mid_val > target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return false;
  }

  void findMinIndex(vector<int>& nums) {
    min_value_index = findSubArrayMinIndex(nums, 0, nums.size() - 1);
  }

  int findSubArrayMinIndex(vector<int>& nums, int left, int right) {
    int mid;
    while (true) {
      if (left == right) {
        return left;
      }
      if (right - left == 1) {
        return nums[left] <= nums[right] ? left : right;
      }

      if (nums[left] < nums[right]) {
        return left;
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
        while (left < mid && nums[left] == nums[left + 1]) {
          left++;
        }
        while (right > mid && nums[right] == nums[right - 1]) {
          right--;
        }
      }
    }
  }
};
