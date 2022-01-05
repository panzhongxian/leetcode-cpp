#include "base.h"

class Solution {
 public:
  string makeFancyString(string s) {
    string ret;
    char prev_char = '0';
    int prev_continuous_count = 0;

    for (char c : s) {
      if (prev_char != c) {
        ret.push_back(c);
        prev_char = c;
        prev_continuous_count = 1;
      } else if (prev_continuous_count < 2) {
        ret.push_back(c);
        prev_continuous_count++;
      }
    }

    return ret;
  }
};
