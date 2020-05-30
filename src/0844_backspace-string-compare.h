#include "base.h"

class Solution {
 public:
  string GetRealString(string S) {
    char s[S.size()];
    size_t s_p = 0;
    for (auto c : S) {
      switch (c) {
        case '#':
          if (s_p > 0) {
            s_p--;
          }
          break;
        default:
          s[s_p++] = c;
      }
    }
    return string(s, s_p);
  }
  bool backspaceCompare(string S, string T) {
    return GetRealString(S) == GetRealString(T);
  }
};
