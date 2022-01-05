#include "base.h"

class Solution {
 public:
  vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    vector<int> ret;
    for (int i = 0; i < index.size(); i++) {
      ret.insert(ret.begin() + index[i], 1, nums[i]);
    }
    return ret;
  }
};
