#include "base.h"

class Solution {
 public:
  int firstUniqChar(string s) {
    int m[128];
    for (int i = 'a'; i <= 'z'; i++) {
      m[i] = -1;
    }
    for (int i = 0; i < s.size(); i++) {
      if (m[s[i]] == -2) {
        continue;
      } else if (m[s[i]] == -1) {
        m[s[i]] = i;
      } else {
        m[s[i]] = -2;
      }
    }
    int ret = -1;
    for (int i = 'a'; i <= 'z'; i++) {
      if (m[i] >= 0) {
        if (ret == -1) {
          ret = m[i];
        } else if (ret > m[i]) {
          ret = m[i];
        }
      }
    }
    return ret;
  }
};
