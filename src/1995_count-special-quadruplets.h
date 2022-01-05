#include "base.h"

class Solution {
 public:
  int countQuadruplets(vector<int>& nums) {
    int ret = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        for (int k = j + 1; k < nums.size(); k++) {
          int three_sum = nums[i] + nums[j] + nums[k];
          for (int l = k + 1; l < nums.size(); l++) {
            if (three_sum == nums[l]) {
              ret++;
            }
          }
        }
      }
    }
    return ret;
  }
};
