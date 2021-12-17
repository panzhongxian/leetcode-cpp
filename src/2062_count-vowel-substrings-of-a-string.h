#include "base.h"

class Solution {
 public:
  static inline int get_vowel_index(char c) {
    static map<char, int> m{{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
    return 1 << m[c];
  }

  size_t get_next_longest_vowel_substr(const string& s, string* vowel_substr,
                                       size_t pos) {
    if (pos == string::npos) {
      *vowel_substr = "";
      return pos;
    }
    auto p = s.find_first_of("aeiou", pos);
    if (p == string::npos) {
      *vowel_substr = "";
      return p;
    }

    pos = s.find_first_not_of("aeiou", p);
    *vowel_substr = s.substr(p, pos - p);
    return pos;
  }

  int count_all_vowel_substr(const string& s) {
    if (s.size() < 5) {
      return 0;
    }
    int vv[s.size()][s.size()];
    int ret = 0;

    for (int i = 0; i < s.size(); i++) {
      vv[i][i] = get_vowel_index(s[i]);
      for (int j = i + 1; j < s.size(); j++) {
        vv[i][j] = get_vowel_index(s[j]) | vv[i][j - 1];
        if (vv[i][j] == 0b11111) {
          ret += 1;
        }
      }
    }
    return ret;
  }

  int countVowelSubstrings(string word) {
    auto ret = 0;
    size_t pos = 0;
    string vowel_substr;
    while (true) {
      pos = get_next_longest_vowel_substr(word, &vowel_substr, pos);
      if (vowel_substr.empty()) {
        return ret;
      }
      ret += count_all_vowel_substr(vowel_substr);
    }
    return ret;
  }
};
