#include "base.h"

class Solution {
 public:
  int lengthOfLastWord(string s) {
    int ret = 0;
    int pre_word_len = 0;
    for (auto c : s) {
      if (c == ' ') {
        if (ret != 0) {
          pre_word_len = ret;
        }
        ret = 0;
      } else {
        ret++;
      }
    }
    return ret == 0 ? pre_word_len : ret;
  }
};
