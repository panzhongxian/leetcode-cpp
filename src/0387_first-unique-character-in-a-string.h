#include "base.h"

class Solution {
 public:
  int firstUniqChar(string s) {
    int hash[26];
    // -2: no appearance
    // -1: repeated
    // >=0: unique index
    for (size_t i = 0; i < 26; ++i) {
      hash[i] = -2;
    }

    for (size_t i = 0; i < s.size(); ++i) {
      char c = s[i];
      if (hash[c - 'a'] == -2) {
        hash[c - 'a'] = i;
      } else {
        hash[c - 'a'] = -1;
      }
    }
    int ret = -1;
    for (size_t i = 0; i < 26; ++i) {
      if (hash[i] < 0) {
        continue;
      }

      ret = (ret == -1) ? hash[i] : min(ret, hash[i]);
    }
    return ret;
  }
};
