#include "base.h"

class Solution {
 public:
  string addStrings(string num1, string num2) {
    if (num1.size() < num2.size()) {
      swap(num1, num2);
    }
    string ret;
    reverse(num1.begin(), num1);
    reverse(num2.begin(), num2);
    int carry = 0;
    int digit = 0;

    for (size_t i = 0; i < nums2.size(); ++i) {
    }
  }
};
