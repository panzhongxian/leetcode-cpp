#include <vector>

using std::vector;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    int k = 1;
    int cur_repeate_time = 1;

    int nums_len = nums.size();
    for (int i = 1; i < nums_len; i++) {
      if (nums[i] == nums[k - 1]) {
        cur_repeate_time += 1;
      } else {
        cur_repeate_time = 1;
      }
      if (cur_repeate_time > 2) {
        continue;
      }
      nums[k++] = nums[i];
    }
    return k;
  }
};
