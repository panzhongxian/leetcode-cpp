#include "base.h"

class Solution {
 public:
  size_t get_next_word(string& sentence, size_t pos, string* word) {
    auto p = sentence.find_first_not_of(' ', pos);
    if (p == string::npos) {
      *word = "";
      return string::npos;
    }

    pos = sentence.find(' ', p);
    if (pos == string::npos) {
      *word = sentence.substr(p);
      return string::npos;
    } else {
      *word = sentence.substr(p, pos - p);
      return ++pos;
    }
  }

  string toGoatLatin(string sentence) {
    size_t pos = 0;
    int i = 1;
    string ret;
    string word;
    while (true) {
      pos = get_next_word(sentence, pos, &word);
      if (word.empty()) {
        break;
      }
      if (!ret.empty()) {
        ret += " ";
      }
      switch (word[0]) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
          ret += word + "ma";
          break;
        default:
          ret += word.substr(1) + word.substr(0, 1) + "ma";
      }
      ret += string(i++, 'a');
    }
    return ret;
  }
};
