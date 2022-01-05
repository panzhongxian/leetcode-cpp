#include "base.h"

class Solution {
 public:
  string reformatNumber(string number) {
    string ret;
    int i = 0;
    for (char c : number) {
      if (c == ' ' || c == '-') {
        continue;
      }
      ret.push_back(c);
      i++;
      if (i == 3) {
        i = 0;
        ret.push_back('-');
      }
    }
    if (i == 0) {
      ret.pop_back();
    } else if (i == 1) {
      swap(ret[ret.size() - 2], ret[ret.size() - 3]);
    }
    return ret;
  }
};
