#include "base.h"

class Solution {
 public:
  int countCharacters(vector<string>& words, string chars) {
    int m[26] = {0};
    auto ret = 0;
    for (auto c : chars) {
      m[c - 'a']++;
    }
    int m_cp[26];
    for (auto& word : words) {
      memcpy(m_cp, m, sizeof(int) * 26);
      bool good_flag = true;
      for (auto c : word) {
        if (--m_cp[c - 'a'] < 0) {
          good_flag = false;
          break;
        }
      }
      if (good_flag) {
        ret += word.size();
      }
    }
    return ret;
  }
};
