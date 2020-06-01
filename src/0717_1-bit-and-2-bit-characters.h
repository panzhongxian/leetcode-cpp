#include "base.h"

class Solution {
 public:
  bool isOneBitCharacter(vector<int>& bits) {
    bool ret = false;
    for (size_t i = 0; i < bits.size();) {
      if (bits[i] == 1) {
        i += 2;
        ret = false;
      } else {
        i++;
        ret = true;
      }
    }
    return ret;
  }
};
