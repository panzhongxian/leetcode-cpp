#include "base.h"

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int end_idx = m + n - 1;
    m--;
    n--;
    while (n >= 0 && m >= 0) {
      if (nums1[m] > nums2[n]) {
        nums1[end_idx--] = nums1[m--];
      } else {
        nums1[end_idx--] = nums2[n--];
      }
    }
    while (n >= 0) {
      nums1[end_idx--] = nums2[n--];
    }
  }
};
