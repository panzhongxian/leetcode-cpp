class Solution {
public:
  int countGoodSubstrings(string s) {
    int ret = 0;
    for (int i = 2; i < s.size(); i++) {
      if (s[i] != s[i - 1] && s[i] != s[i - 2] && s[i - 1] != s[i - 2]) {
        ret++;
      }
    }
    return ret;
  }
};
