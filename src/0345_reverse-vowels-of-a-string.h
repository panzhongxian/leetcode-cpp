#include "base.h"

class Solution {
 public:
  bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
  }
  string reverseVowels(string s) {
    if (s.size() <= 1) {
      return s;
    }
    int p1 = 0;
    int p2 = s.size() - 1;

    while (p1 < p2) {
      while (p1 < p2 && !isVowel(s[p1])) {
        p1++;
      }
      while (p1 < p2 && !isVowel(s[p2])) {
        p2--;
      }
      swap(s[p1++], s[p2--]);
    }
    return s;
  }
};
