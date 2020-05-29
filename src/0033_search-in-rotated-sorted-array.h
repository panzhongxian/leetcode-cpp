#include "base.h"
class Solution {
 public:
  int searchMaxIdx(const vector<int>& nums) {
    if (nums.size() == 0) {
      return -1;
    }
    if (nums.size() == 1) {
      return 0;
    }

    size_t left_idx, right_idx, mid_idx;
    left_idx = 0;
    right_idx = nums.size() - 1;

    int left, mid, right;
    while (left_idx < right_idx) {
      mid_idx = (left_idx + right_idx) / 2;
      left = nums[left_idx];
      mid = nums[mid_idx];
      right = nums[right_idx];

      if (mid > left) {
        left_idx = mid_idx;
      } else if (mid == left) {
        return mid > right ? left_idx : right_idx;
      } else {
        right_idx = mid_idx;
      }
    }
    assert(false);
    return -1;
  }

  int search(const vector<int>& nums, int target) {
    if (nums.size() == 0) {
      return -1;
    }
    if (nums.size() == 1) {
      return nums[0] == target ? 0 : -1;
    }
    size_t max_idx = searchMaxIdx(nums);
    size_t shift = nums.size() - max_idx - 1;

    size_t len = nums.size();
    size_t left_idx = 0;
    size_t right_idx = len - 1;
    size_t mid_idx;
    int left, mid, right;
#define SHIFT(x) ((x + len - shift) % len)
    while (left_idx < right_idx) {
      mid_idx = (left_idx + right_idx) / 2;

      left = nums[SHIFT(left_idx)];
      mid = nums[SHIFT(mid_idx)];
      right = nums[SHIFT(right_idx)];

      if (mid == target) {
        return SHIFT(mid_idx);
      }
      if (mid == left) {
        if (target == mid) {
          return SHIFT(mid_idx);
        }
        if (target == right) {
          return SHIFT(right_idx);
        }
        return -1;
      }

      if (mid > target) {
        right_idx = mid_idx;
      } else {
        left_idx = mid_idx;
      }
    }
    return -1;
  }
};
