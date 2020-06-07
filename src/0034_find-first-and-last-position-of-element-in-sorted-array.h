#include "base.h"

class Solution {
  int target;

 public:
  int FindFirstPos(const vector<int>& nums, int left, int right) {
    // 左闭右闭区间
    int mid;
    while (left < right) {
      // cout << "[" << left << ", " << right << "]" << endl;
      mid = (left + right) / 2;
      if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return nums[left] == target ? left : -1;
  }

  int FindLastPos(const vector<int>& nums, int left, int right) {
    int mid;
    while (left < right) {
      mid = (left + right + 1) / 2;
      if (nums[mid] > target) {
        right = mid - 1;
      } else {
        left = mid;
      }
    }
    return nums[right] == target ? right : -1;
  }

  vector<int> searchRange(const vector<int>& nums, int target) {
    if (nums.size() == 0) {
      return {-1, -1};
    }
    if (nums.size() == 1) {
      if (nums[0] == target) {
        return {0, 0};
      } else {
        return {-1, -1};
      }
    }
    int left, right;
    this->target = target;
    left = FindFirstPos(nums, 0, nums.size() - 1);
    if (left == -1) {
      return vector<int>({-1, -1});
    }
    right = FindLastPos(nums, left, nums.size() - 1);
    return {left, right};
  }
};
