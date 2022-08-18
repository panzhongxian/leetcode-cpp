#include <vector>
using namespace std;
class Solution {
 public:
  int DecreaseToZigzag(const vector<int>& nums, int start) {
    int ret = 0;
    for (int i = start; i < nums.size(); i += 2) {
      int cur_num = nums[i];
      int target;
      if (i == 0) {
        target = nums[i + 1] - 1;
      } else if (i + 1 == nums.size()) {
        target = nums[i - 1] - 1;
      } else {
        target = min(nums[i - 1], nums[i + 1]) - 1;
      }

      if (nums[i] > target) {
        ret += nums[i] - target;
      }
    }
    return ret;
  }

  int movesToMakeZigzag(const vector<int>& nums) {
    if (nums.size() <= 2) {
      return 0;
    }
    return min(DecreaseToZigzag(nums, 0), DecreaseToZigzag(nums, 1));
  }
};
