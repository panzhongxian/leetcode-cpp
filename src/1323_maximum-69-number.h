#include "base.h"

class Solution {
 public:
  int maximum69Number(int num) {
    string s = to_string(num);
    size_t pos = s.find('6');
    if (pos == string::npos) {
      return num;
    }

    s[pos] = '9';
    return atoi(s.c_str());
  }
};
