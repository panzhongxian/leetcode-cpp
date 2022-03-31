class Solution {
 public:
  bool isSubstring(string& s, string& trigger) {
    if (trigger.size() >= s.size()) {
      return trigger == s;
    }
    int j = 0;
    for (int i = 0; i < trigger.size(); i++) {
      while (j < s.size() && s[j] != trigger[i]) {
        j++;
        if (j == s.size()) {
          return false;
        }
      }
    }
    return true;
  }
  string findLongestWord(string s, vector<string>& dictionary) {
    string ret;
    for (auto& word : dictionary) {
      if (word.size() < ret.size() ||
          (word.size() == ret.size() && word > ret)) {
        continue;
      }
      if (isSubstring(s, word)) {
        ret = word;
      }
    }
    return ret;
  }
};
