#include "base.h"

class Solution {
 public:
  vector<double> medianSlidingWindow(const vector<int>& nums, int k) {
    vector<double> ret;
    multiset<int> s(nums.begin(), nums.begin() + k);
    auto mid = next(s.begin(), (k - 1) / 2);
    for (size_t i = k;; ++i) {
      ret.push_back(0.5 * (*mid) + 0.5 * (*next(mid, (k + 1) % 2)));
      if (i == nums.size()) {
        break;
      }

      s.insert(nums[i]);
      if (nums[i] < *mid) {
        mid--;
      }
      if (nums[i - k] <= *mid) {
        mid++;
      }
      s.erase(s.lower_bound(nums[i - k]));
    }
    return ret;
  }
};
