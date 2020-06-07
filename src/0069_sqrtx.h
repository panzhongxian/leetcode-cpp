#include "base.h"

class Solution {
 public:
  int mySqrt(int x) {
    if (x == 0 || x == 1) {
      return x;
    }
    int bit_len = 0;
    int y = x;
    while (y) {
      y >>= 1;
      bit_len++;
    }
    int start = 1 << ((bit_len - 1) / 2);
    int stop = start << 1;
    int mid;
    while (start < stop) {
      mid = (start + stop + 1) / 2;
      int quotient = x / mid;
      if (mid == quotient) {
        return mid;
      }
      if (quotient < mid) {
        stop = mid - 1;
      } else {
        start = mid;
      }
    }
    return start;
  }
};
