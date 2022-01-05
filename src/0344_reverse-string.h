#include "base.h"

class Solution {
 public:
  void reverseString(vector<char>& s) {
    if (s.size() <= 1) {
      return;
    }
    int p1 = 0;
    int p2 = s.size() - 1;
    while (p2 > p1) {
      char c = s[p1];
      s[p1] = s[p2];
      s[p2] = c;
      p1++;
      p2--;
    }
  }
};
