class Solution {
 public:
  int isPrefixOfWord(string sentence, string searchWord) {
    sentence = " " + sentence;
    searchWord = " " + searchWord;
    auto pos = sentence.find(searchWord);
    if (pos == string::npos) {
      return -1;
    }
    int ret = 1;
    for (int i = 0; i < pos; i++) {
      if (sentence[i] == ' ') {
        ret++;
      }
    }
    return ret;
  }
};
