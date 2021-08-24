#include <algorithm>
#include <vector>

using std::min;
using std::vector;

class Solution {
 public:
  int jump(vector<int>& nums) {
    int nums_len = nums.size();
    if (nums_len <= 1) {
      return 0;
    }

    vector<int> min_steps(nums_len, 0);
    for (int i = nums_len - 2; i >= 0; i--) {
      if ((i + nums[i]) >= nums_len) {
        min_steps[i] = 1;
      } else {
        min_steps[i] = 1 + *min_element(min_steps.begin() + i + 1,
                                        min_steps.begin() + i + 1 + nums[i]);
      }
    }
    return min_steps[0];
  }
};
