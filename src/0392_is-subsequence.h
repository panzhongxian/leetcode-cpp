#include "base.h"
class Solution {
 public:
  bool isSubsequence(string s, string t) {
    size_t i = 0;
    size_t j = 0;
    while (i < s.size() && j < t.size()) {
      while (s[i] != t[j]) {
        j++;
        if (j >= t.size()) {
          return false;
        }
      }

      i++;
      j++;
    }
    return i == s.size();
  }
};
