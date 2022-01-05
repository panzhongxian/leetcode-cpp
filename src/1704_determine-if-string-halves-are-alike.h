#include "base.h"

class Solution {
 public:
  inline bool is_vowel(char c) {
    switch (c) {
      case 'a':
      case 'A':
      case 'e':
      case 'E':
      case 'i':
      case 'I':
      case 'o':
      case 'O':
      case 'u':
      case 'U':
        return true;
      default:
        return false;
    }
  }
  bool halvesAreAlike(string s) {
    int i = 0;
    int counter = 0;
    for (; i < s.size() / 2; i++) {
      if (is_vowel(s[i])) {
        counter++;
      }
    }
    for (; i < s.size(); i++) {
      if (is_vowel(s[i])) {
        counter--;
      }
    }
    return counter == 0;
  }
};
