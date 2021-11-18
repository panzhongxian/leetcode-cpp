class Solution {
 public:
  bool checkSubStr(string& s, int pos, int len) {
    int j = pos;
    for (int i = 0; i < len; i++, j++) {
      if (s[i] != s[j]) {
        return false;
      }
    }
    return true;
  }
  bool repeatedSubstringPattern(string s) {
    int s_len = s.size();
    for (int i = 1; i < s_len; i++) {
      if (s_len % i != 0) {
        continue;
      }
      int j = i;
      if (j == s.size()) {
        continue;
      }
      while (j < s_len) {
        if (!checkSubStr(s, j, i)) {
          break;
        }
        j += i;
      }
      if (j == s_len) return true;
    }
    return false;
  }
};
