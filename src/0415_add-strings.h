#include "base.h"

class Solution {
 public:
  string addStrings(string num1, string num2) {
    if (num1.size() < num2.size()) {
      swap(num1, num2);
    }
    string ret;
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int carry = 0;
    int digit = 0;

    int i;
    for (i = 0; i < num2.size(); ++i) {
      digit = num1[i] + num2[i] - '0' - '0' + carry;
      if (carry = digit >= 10 ? 1 : 0) {
        digit -= 10;
      }
      ret.push_back(digit + '0');
    }
    for (; i < num1.size(); ++i) {
      digit = num1[i] - '0' + carry;
      if (carry = digit >= 10 ? 1 : 0) {
        digit -= 10;
      }
      ret.push_back(digit + '0');
    }
    if (carry) {
      ret.push_back('1');
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }
};
