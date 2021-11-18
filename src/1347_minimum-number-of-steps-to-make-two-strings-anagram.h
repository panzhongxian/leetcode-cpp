class Solution {
 public:
  int minSteps(string s, string t) {
    int ret = 0;
    int m[256];
    for (int i = 'a'; i <= 'z'; i++) {
      m[i] = 0;
    }
    for (char c : s) {
      m1[c]++;
    }
    for (char c : t) {
      if (m1[c]) {
        m1[c]--;
      } else {
        ret++;
      }
    }
    return ret;
  }
};
