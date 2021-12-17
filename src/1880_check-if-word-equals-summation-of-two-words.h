class Solution {
 public:
  int64_t word_value(const string& s) {
    int64_t ret = 0;
    for (char c : s) {
      ret = ret * 10 + (c - 'a');
    }
    return ret;
  }
  bool isSumEqual(string firstWord, string secondWord, string targetWord) {
    return word_value(firstWord) + word_value(secondWord) ==
           word_value(targetWord);
  }
};
