#include "base.h"

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int ret = 0;
    for (int i = 0; i < 32; i++) {
      if (1 & n) {
        ret++;
      }
      n >>= 1;
    }
    return ret;
  }
};
