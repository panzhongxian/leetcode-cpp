#include "base.h"

class Solution {
 public:
  Solution() {
    ret_vec[0] = 0;
    ret_vec[1] = 1;
    ret_vec[2] = 1;
    max_idx = 2;
  }
  int integerBreak(int n) {
    if (n <= max_idx) {
      return ret_vec[n];
    }
    int cur_max;
    for (int i = max_idx; i <= n; i++) {
      cur_max = i - 1;
      for (int j = 2; j <= i / 2; j++) {
        int t = max(j, ret_vec[j]) * max(i - j, ret_vec[i - j]);
        if (t > cur_max) {
          cur_max = t;
        }
      }
      ret_vec[i] = cur_max;
      max_idx = i;
    }
    return ret_vec[n];
  }

 private:
  int ret_vec[59];
  int max_idx;
};
