class Solution {
 public:
  int maxLengthBetweenEqualCharacters(string s) {
    int m[26] = {0};
    int ret = -1;
    for (int i = 0; i < s.size(); i++) {
      if (m[s[i] - 'a'] == 0) {
        m[s[i] - 'a'] = i + 1;
      } else {
        ret = max(ret, i - m[s[i] - 'a']);
      }
    }
    return ret;
  }
};
