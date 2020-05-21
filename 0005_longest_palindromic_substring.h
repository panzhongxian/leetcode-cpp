#include "base.h"
class Solution {
 public:
  int CheckOddPalindrome(const string &s, int i) {
    int n = 1;
    int s_len = s.size();
    for (; i + n < s_len && i - n >= 0; ++n) {
      if (s[i + n] != s[i - n]) {
        return n - 1;
      }
    }
    return n - 1;
  }

  int CheckEvenPalindrome(const string &s, int i) {
    int n = 0;
    int s_len = s.size();
    for (; i + n < s_len - 1 && i - n >= 0; ++n) {
      if (s[i + 1 + n] != s[i - n]) {
        return n;
      }
    }
    return n;
  }

  string longestPalindrome(string s) {
    int start_index = 0;
    int max_length = 1;
    int len;
    for (size_t i = 0; i < s.size(); ++i) {
      int n = CheckOddPalindrome(s, i);
      len = 2 * n + 1;
      if (len > max_length) {
        max_length = len;
        start_index = i - n;
      }
    }

    for (size_t i = 0; i + 1 < s.size(); ++i) {
      int n = CheckEvenPalindrome(s, i);
      len = 2 * n;
      if (len > max_length) {
        max_length = len;
        start_index = i - n + 1;
      }
    }
    return s.substr(start_index, max_length);
  }
};
