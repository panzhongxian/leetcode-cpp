#include <iostream>
#include <string>
using namespace std;
class Solution {
 public:
  int CheckLetter(char c) {
    if (c >= 'a' && c <= 'z') {
      return c;
    }
    if (c >= 'A' && c <= 'Z') {
      return c - 'A' + 'a';
    }
    if (c >= '0' && c <= '9') {
      return c;
    }
    return -1;
  }

  bool isPalindrome(string s) {
    if (s.empty()) {
      return true;
    }
    int p1, p2;
    p1 = 0;
    p2 = s.size() - 1;
    while (p1 <= p2) {
      int i1 = CheckLetter(s[p1]);
      if (i1 < 0) {
        p1++;
        continue;
      }
      int i2 = CheckLetter(s[p2]);
      if (i2 < 0) {
        p2--;
        continue;
      }
      p1++;
      p2--;
      if (i1 != i2) {
        return false;
      }
    }
    return true;
  }
};
