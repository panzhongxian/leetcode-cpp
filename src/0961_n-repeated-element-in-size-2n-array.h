#include "base.h"

class Solution {
 public:
  int repeatedNTimes(vector<int>& A) {
    unordered_map<int, bool> m;
    for (int i : A) {
      if (m.find(i) != m.end()) {
        return i;
      }
      m[i] = true;
    }
    return 0;
  }
};
