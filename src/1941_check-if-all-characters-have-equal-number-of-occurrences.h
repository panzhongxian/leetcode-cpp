class Solution {
 public:
  bool areOccurrencesEqual(string s) {
    int m[26];
    memset(m, 0, sizeof(int) * 26);
    for (char c : s) {
      m[c - 'a']++;
    }
    int occur_time = -1;
    for (int i = 0; i < 26; i++) {
      int c = m[i];
      if (c != 0) {
        if (occur_time == -1) {
          occur_time = c;
        } else if (occur_time != c) {
          return false;
        }
      }
    }
    return true;
  }
};
