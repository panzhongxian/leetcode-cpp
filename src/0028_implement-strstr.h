#include "base.h"

class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle.length() > haystack.length()) {
      return -1;
    }
    bool found_flag = false;
    for (size_t i = 0; i <= haystack.length() - needle.length(); ++i) {
      cout << "i: " << i << endl;
      found_flag = true;
      for (size_t j = 0; j < needle.length(); ++j) {
        if (haystack[i + j] != needle[j]) {
          found_flag = false;
          break;
        }
      }
      if (found_flag) return i;
    }
    return -1;
  }
};
