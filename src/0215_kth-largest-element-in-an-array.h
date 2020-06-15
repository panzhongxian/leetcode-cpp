#include "base.h"

class Solution {
 public:
  int findKthLargest(const vector<int>& nums, int k) {
    multiset<int> s(nums.begin(), nums.begin() + k);
    for (size_t i = k; i < nums.size(); ++i) {
      if (nums[i] > *(s.begin())) {
        s.insert(nums[i]);
        s.erase(s.begin());
      }
    }
    return *(s.begin());
  }
};
