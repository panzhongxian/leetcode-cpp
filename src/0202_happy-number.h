#include "base.h"

class Solution {
 public:
  int Deduce(int n) {
    int ret = 0;
    while (n) {
      ret += (n % 10) * (n % 10);
      n /= 10;
    }
    return ret;
  }
  bool isHappy(int n) {
    unordered_set<int> dset({n});
    while (true) {
      n = Deduce(n);
      if (n == 1) {
        return true;
      }
      if (dset.find(n) != dset.end()) {
        return false;
      }
      dset.insert(n);
    }
  }
};
