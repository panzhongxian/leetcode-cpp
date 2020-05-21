#include "base.h"

const int max_palindrome = 2147447412;

class Solution {
 public:
  bool isPalindrome(int x) {
    if (!x) return true;
    if (x < 0 || x % 10 == 0) return false;
    int left = x;
    int right = 0;
    while (left > right) {
      right = right * 10 + left % 10;
      left = left / 10;
    }
    return left == right || abs(right - left * 10) < 10;
  }
};
