class Solution {
 public:
  int longestPalindrome(string s) {
    int m[128] = {0};
    int ret = 0;
    for (char c : s) {
      if (m[c]) {
        m[c] = 0;
        ret += 2;
      } else {
        m[c] = 1;
      }
    }
    if (s.size() > ret) {
      ret++;
    }
    return ret;
  }
};
