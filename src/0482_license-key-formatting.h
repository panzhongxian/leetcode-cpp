#include "base.h"
class Solution {
 public:
  string licenseKeyFormatting(string s, int k) {
    constexpr int case_diff = 'A' - 'a';
    int counter = 0;
    string ret;
    for (int i = s.size() - 1; i >= 0; i--) {
      char cur_char;
      if (s[i] == '-') continue;
      if (s[i] <= 'z' && s[i] >= 'a') {
        s[i] += case_diff;
      }
      ret.push_back(s[i]);
      if (counter++; counter == k) {
        ret.push_back('-');
        counter = 0;
      }
    }

    if (!ret.empty() && ret[ret.size() - 1] == '-') {
      ret.pop_back();
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }
};
