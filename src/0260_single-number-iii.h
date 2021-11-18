#include "base.h"

class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    int xor_result = 0;
    for (int num : nums) {
      xor_result ^= num;
    }

    int mask = 1;
    while (true) {
      if (xor_result & 1) {
        break;
      }
      xor_result >>= 1;
      mask <<= 1;
    }

    vector<int> ret{0, 0};
    for (int num : nums) {
      if (num & mask) {
        ret[0] ^= num;
      } else {
        ret[1] ^= num;
      }
    }
    return ret;
  }
};
