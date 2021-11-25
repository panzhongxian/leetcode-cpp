class Solution {
public:
  bool isPrefixString(string s, vector<string> &words) {
    int shift = 0;
    for (auto &word : words) {
      if (shift == s.size()) {
        return true;
      }
      if (strncmp(s.c_str() + shift, word.c_str(), word.size()) != 0) {
        return false;
      }
      shift += word.size();
    }
    return shift == s.size();
  }
};
