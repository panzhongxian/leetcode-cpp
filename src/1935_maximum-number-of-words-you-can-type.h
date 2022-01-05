#include "base.h"

class Solution {
 public:
  int canBeTypedWords(string text, string brokenLetters) {
    int ret = 0;
    text.push_back(' ');

    int32_t broken_letters = 0;
    for (char c : brokenLetters) {
      broken_letters |= (1 << (c - 'a'));
    }

    int32_t word_letters = 0;
    for (char c : text) {
      if (c == ' ') {
        if (!(word_letters & broken_letters)) {
          ret++;
        }
        memset(&word_letters, 0, sizeof(word_letters));
      } else {
        word_letters |= (1 << (c - 'a'));
      }
    }
    return ret;
  }
};
