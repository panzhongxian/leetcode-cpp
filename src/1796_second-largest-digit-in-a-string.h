#include "base.h"

class Solution {
 public:
  int secondHighest(string s) {
    map<char, bool> mp;
    for (char c : s) {
      if (c >= '0' && c <= '9') {
        mp[c] = true;
      }
    }
    if (mp.size() < 2) {
      return -1;
    }
    return prev(prev(mp.end()))->first - '0';
  }
};
