#include <algorithm>
#include <vector>

using std::max;
using std::min;
using std::vector;

class Solution {
 public:
  bool increasingTriplet(const vector<int>& nums) {
    if (nums.size() < 3) {
      return false;
    }
    vector<bool> exist_smaller(nums.size(), false);
    vector<bool> exist_larger(nums.size(), false);
    int smallest_before_i = nums[0];
    int largest_after_i = nums[nums.size() - 1];

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > smallest_before_i) {
        exist_smaller[i] = true;
      } else {
        smallest_before_i = nums[i];
      }
    }
    for (int i = nums.size() - 2; i > 0; --i) {
      if (nums[i] < largest_after_i) {
        exist_larger[i] = true;
      } else {
        largest_after_i = nums[i];
      }
    }

    for (int i = 0; i < nums.size(); i++) {
      if (exist_smaller[i] && exist_larger[i]) return true;
    }
    return false;
  }
};
