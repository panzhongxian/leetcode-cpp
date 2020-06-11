#include "base.h"

class Solution {
 public:
  double findMedianSortedArrays(const vector<int>& n1, const vector<int>& n2) {
    vector<int> nums1;
    vector<int> nums2;
    if (n1.size() < n2.size()) {
      nums1 = n2;
      nums2 = n1;
    } else {
      nums1 = n1;
      nums2 = n2;
    }

    int m = nums1.size();
    int n = nums2.size();
    bool odd_flag = (m + n) % 2;
    if (n == 0) {
      return odd_flag ? nums1[(m / 2)]
                      : 0.5 * (nums1[m / 2] + nums1[m / 2 - 1]);
    }

    // 无论奇数偶数都是一样的区间范围
    int start = (m - n) / 2;
    int end = (m + n) / 2;
    int i, j;

    // m+n 为奇数
    while (start <= end) {
      i = (start + end) / 2;
      j = ((m + n) / 2 - i);

      if (j == 0) {
        if (nums1[i - 1] > nums2[0]) {
          end = i - 1;
        } else {
          break;
        }
      } else if (j == n) {
        if (nums1[i] < nums2[j - 1]) {
          start = i + 1;
        } else {
          break;
        }
      } else if (nums1[i] < nums2[j - 1]) {
        start = i + 1;
      } else if (nums1[i - 1] > nums2[j]) {
        end = i - 1;
      } else {
        break;
      }
    }

    if (j == 0) {
      if (odd_flag) {
        return min(nums1[i], nums2[j]);
      } else if (i == m) {
        return 0.5 * (nums1[i - 1] + nums2[j]);
      } else {
        return 0.5 * (nums1[i - 1] + min(nums1[i], nums2[j]));
      }
    } else if (j == n) {
      if (odd_flag) {
        return nums1[i];
      } else if (i == 0) {
        return 0.5 * (nums1[i] + nums2[j - 1]);
      } else {
        return 0.5 * (max(nums1[i - 1], nums2[j - 1]) + nums1[i]);
      }
    } else {
      if (odd_flag) {
        return min(nums1[i], nums2[j]);
      } else {
        return 0.5 *
               (max(nums1[i - 1], nums2[j - 1]) + min(nums1[i], nums2[j]));
      }
    }

    assert(false);
    return 0;
  }
};
