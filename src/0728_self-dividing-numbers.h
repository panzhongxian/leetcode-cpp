#include "base.h"

class Solution {
 public:
  bool is_dividing_number(int i) {
    for (char c : to_string(i)) {
      if (c == '0') {
        return false;
      }
      if (i % (c - '0') != 0) {
        return false;
      }
    }
    return true;
  }
  vector<int> selfDividingNumbers(int left, int right) {
    vector<int> ret;
    for (int i = left; i <= right; i++) {
      if (is_dividing_number(i)) {
        ret.push_back(i);
      }
    }
    return ret;
  }
};
