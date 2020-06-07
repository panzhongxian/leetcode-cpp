#include "base.h"

class Solution {
 public:
  int findUnsortedSubarray(const vector<int>& nums) {
    if (nums.size() <= 1) {
      return 0;
    }

    vector<int> max_from_left(nums.size());
    vector<int> min_from_right(nums.size());
    max_from_left[0] = nums[0];
    min_from_right[nums.size() - 1] = nums[nums.size() - 1];

    for (size_t i = 1; i < nums.size(); ++i) {
      size_t j = nums.size() - 1 - i;
      max_from_left[i] = max(max_from_left[i - 1], nums[i]);
      min_from_right[j] = min(min_from_right[j + 1], nums[j]);
    }

    COUT_VALUE(max_from_left);
    COUT_VALUE(min_from_right);

    int left_start_idx = -1;
    int i = 0;
    for (; i < nums.size(); ++i) {
      if (max_from_left[i] != min_from_right[i]) {
        left_start_idx = i;
        break;
      }
    }

    if (left_start_idx == -1) {
      return 0;
    }

    for (i = nums.size() - 1; i >= 0; --i) {
      if (max_from_left[i] != min_from_right[i]) {
        return i - left_start_idx + 1;
      }
    }
    return 0;
  }
};
