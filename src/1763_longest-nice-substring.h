#include "base.h"
class Solution {
 private:
  class StrInfo {
    int32_t lowers{0};
    int32_t uppers{0};

   public:
    bool is_nice() { return lowers == uppers; };
    void insert(char c) {
      if (c >= 'a' && c <= 'z') {
        lowers |= (1 << (c - 'a'));
      } else {
        uppers |= (1 << (c - 'A'));
      }
    }
  };

 public:
  string longestNiceSubstring(string s) {
    string ret;
    StrInfo vv[s.size()][s.size()];
    for (int i = 0; i < s.size(); i++) {
      vv[i][i].insert(s[i]);
      for (int j = i + 1; j < s.size(); j++) {
        vv[i][j] = vv[i][j - 1];
        vv[i][j].insert(s[j]);
      }
    }

    int max_len = 0;
    for (int i = 0; i < s.size(); i++) {
      for (int j = i; j < s.size(); j++) {
        if (vv[i][j].is_nice() && j - i + 1 > max_len) {
          max_len = j - i + 1;
          ret = s.substr(i, max_len);
        }
      }
    }

    return ret;
  }
};
