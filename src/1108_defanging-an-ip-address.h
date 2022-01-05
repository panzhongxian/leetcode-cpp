#include "base.h"

class Solution {
 public:
  string defangIPaddr(string address) {
    string ret;
    for (char c : address) {
      if (c == '.') {
        ret.push_back('[');
        ret.push_back('.');
        ret.push_back(']');
      } else {
        ret.push_back(c);
      }
    }
    return ret;
  }
};
