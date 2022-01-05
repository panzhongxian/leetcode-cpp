#include "base.h"

class Solution {
 public:
  int finalValueAfterOperations(vector<string>& operations) {
    int ret = 0;
    for (auto s : operations) {
      if (s[1] == '-') {
        ret--;
      } else {
        ret++;
      }
    }
    return ret;
  }
};
