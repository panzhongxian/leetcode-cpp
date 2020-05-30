#include "base.h"

class Solution {
 public:
  int rangeBitwiseAnd(int m, int n) {
    if (m < n) {
      swap(m, n);
    }

    unsigned int diff = m - n;
    unsigned int mask = 0;
    mask = ~mask;
    while (diff) {
      diff /= 2;
      mask <<= 1;
    }
    /*
    cout << "m&n: " << hex << (m & n) << endl;
    cout << "mask: " << hex << mask << endl;
    cout << "mask: " << hex << (mask & m & n) << endl;
    */
    return m & n & mask;
  }
};
