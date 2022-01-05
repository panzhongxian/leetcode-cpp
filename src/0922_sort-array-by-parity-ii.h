#include "base.h"

class Solution {
 public:
  vector<int> sortArrayByParityII(vector<int>& A) {
    if (A.size() <= 1) {
      return A;
    }
    vector<int> ret(A.size());
    int p_odd = 1;
    int p_even = 0;
    for (int a : A) {
      if (a & 1) {
        ret[p_odd] = a;
        p_odd += 2;
      } else {
        ret[p_even] = a;
        p_even += 2;
      }
    }
    return ret;
  }
};
