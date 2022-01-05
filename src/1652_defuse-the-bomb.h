#include "base.h"

class Solution {
 public:
  vector<int> decrypt(vector<int>& code, int k) {
    vector<int> ret(code.size(), 0);
    if (k == 0) {
      return ret;
    }

    if (k > 0) {
      for (int i = 1; i <= k; i++) {
        ret[0] += code[i];
      }
      for (int i = 1; i < code.size(); i++) {
        ret[i] = ret[i - 1] - code[i] + code[(i + k) % code.size()];
      }
    } else {
      for (int i = 1; i <= -k; i++) {
        ret[0] += code[code.size() - i];
      }
      for (int i = 1; i < code.size(); i++) {
        ret[i] = ret[i - 1] + code[i - 1] -
                 code[(code.size() + i + k - 1) % code.size()];
      }
    }
    return ret;
  }
};
