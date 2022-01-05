#include "base.h"

class Solution {
 public:
  vector<int> getNoZeroIntegers(int n) {
    int a = 0;
    int b = 0;
    int base = 1;
    while (n) {
      if (n == 1) {
        a += base * 1;
        break;
      }

      int rem = n % 10;
      if (rem == 0) {
        a += base * 1;
        b += base * 9;
        n = n / 10 - 1;
      } else if (rem == 1) {
        a += base * 2;
        b += base * 9;
        n = n / 10 - 1;
      } else {
        a += base * 1;
        b += base * (rem - 1);
        n = n / 10;
      }
      base *= 10;
    }
    return vector<int>{a, b};
  }
};
