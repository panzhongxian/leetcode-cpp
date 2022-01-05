#include "base.h"

class Solution {
 public:
  int findLengthOfLCIS(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    int ret = 0;
    int current_cis_len = 1;
    int current_num = nums[0];
    for (const int& num : nums) {
      if (num > current_num) {
        current_cis_len++;
        current_num = num;
        continue;
      }
      if (current_cis_len > ret) {
        ret = current_cis_len;
      }
      current_cis_len = 1;
      current_num = num;
    }
    return current_cis_len > ret ? current_cis_len : ret;
  }
};
