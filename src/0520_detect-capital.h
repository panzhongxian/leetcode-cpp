#include "base.h"

// case1: USA, case2: leetcode, case3: Google
static inline bool is_lower(char c) { return c >= 'a' && c <= 'z'; }
class Solution {
 public:
  bool detectCapitalUse(string word) {
    if (word.size() <= 1) {
      return true;
    }
    int next_char_case = 0;
    if (is_lower(word[0])) {
      next_char_case = 1;
    } else {
      next_char_case = is_lower(word[1]) ? 1 : 2;
    }
    for (int i = 1; i < word.size(); i++) {
      if (next_char_case == 1) {
        if (!is_lower(word[i])) {
          return false;
        }
      } else {
        if (is_lower(word[i])) {
          return false;
        }
      }
    }

    return true;
  }
};
