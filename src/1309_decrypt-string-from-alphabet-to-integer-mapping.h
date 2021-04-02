#include <iostream>
#include <string>
class Solution {
 public:
  char DecryptNumToChar(int n) { return static_cast<char>(n + 'a' - 1); }
  std::string freqAlphabets(std::string s) {
    std::string ret;
    for (size_t i = 0; i < s.size(); ++i) {
      if (i + 2 < s.size() && s[i + 2] == '#') {
        ret += DecryptNumToChar((s[i] - '0') * 10 + s[i + 1] - '0');
        i += 2;
      } else {
        ret += DecryptNumToChar(s[i] - '0');
      }
    }
    return ret;
  }
};
