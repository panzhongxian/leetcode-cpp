#include "base.h"

class Solution {
 public:
  bool IsPalindrome(const string& word) {
    for (int i = 0; i < word.size() / 2; i++) {
      if (word[i] != word[word.size() - i - 1]) {
        return false;
      }
    }
    return true;
  }
  string firstPalindrome(vector<string>& words) {
    for (auto& word : words) {
      if (IsPalindrome(word)) {
        return word;
      }
    }
    return "";
  }
};
