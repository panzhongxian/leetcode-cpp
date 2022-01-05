#include "base.h"

class Solution {
 public:
  string convertToBase7(int num) {
    bool minus_flag = false;
    if (num == 0) {
      return "0";
    } else if (num < 0) {
      num = -num;
      minus_flag = true;
    }
    string ret;
    while (num) {
      ret.push_back((num % 7) + '0');
      num /= 7;
    }
    reverse(ret.begin(), ret.end());
    if (minus_flag) {
      ret.insert(ret.begin(), 1, '-');
    }
    return ret;
  }
};
