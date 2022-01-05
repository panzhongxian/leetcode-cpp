#include "base.h"

class Solution {
 public:
  bool validate(string& s) {
    int letter_cnt = 0;
    int hyphen_cnt = 0;
    int punctuation_cnt = 0;
    if (s[0] == '-') {
      return false;
    }
    switch (s[s.size() - 1]) {
      case '-':
        return false;
      case '!':
      case '.':
      case ',':
        s.pop_back();
    }

    for (int i = 0; i < s.size(); i++) {
      switch (s[i]) {
        case '-':
          if (hyphen_cnt++ >= 1 || (i == s.size() - 1)) {
            return false;
          }
          break;
        case '!':
        case '.':
        case ',':
          return false;
        default:
          if (s[i] >= '0' && s[i] <= '9') return false;
      }
    }
    return true;
  }
  int countValidWords(string sentence) {
    sentence += " ";
    auto start = sentence.find_first_not_of(" ");
    size_t end;

    int ret = 0;
    while (start != string::npos) {
      end = sentence.find(' ', start);
      auto word = sentence.substr(start, end - start);
      if (validate(word)) {
        ret++;
      }
      start = sentence.find_first_not_of(" ", end);
    }
    return ret;
  }
};
