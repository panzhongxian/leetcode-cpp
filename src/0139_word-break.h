#include "base.h"

class Solution {
 public:
  bool wordBreak(string s, const vector<string>& wordDict) {
    if (s.size() == 0) {
      return true;
    }
    vector<bool> is_sentence(s.size(), false);
    for (size_t i = 0; i < is_sentence.size(); ++i) {
      for (auto& word : wordDict) {
        // 1. start with the word
        // 2. end with the word and the prefix is a sentence.
        if ((i + 1 == word.size() && s.substr(0, word.size()) == word) ||
            (i + 1 > word.size() && is_sentence[i - word.size()] &&
             s.substr(i - word.size() + 1, word.size()) == word)) {
          is_sentence[i] = true;
          break;
        }
      }
    }
    return is_sentence.back();
  }
};
