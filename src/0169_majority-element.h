#include "base.h"

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
  }
};

class Solution2 {
 public:
  int majorityElement(vector<int>& nums) {
    unordered_map<int, int> m;
    int limit = nums.size() / 2;

    for (auto i : nums) {
      m[i]++;
      if (m[i] > limit) {
        return i;
      }
    }
    assert(false);
    return 0;
  }
};

class Solution3 {
 public:
  int majorityElement(vector<int>& nums) {
    int majority = nums[0];
    int count = 1;
    for (size_t i = 1; i < nums.size(); ++i) {
      if (nums[i] == majority) {
        count += 1;
      } else if (count == 1) {
        majority = nums[i];
      } else {
        count -= 1;
      }
    }
    return majority;
  }
};
