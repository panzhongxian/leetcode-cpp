class Solution {
 public:
  int maxNumberOfBalloons(string text) {
    int m[26] = {0};
    for (char c : text) {
      m[c - 'a']++;
    }

    int ret = m['b' - 'a'];
    ret = min(m['a' - 'a'], ret);
    ret = min(m['l' - 'a'] / 2, ret);
    ret = min(m['o' - 'a'] / 2, ret);
    ret = min(m['n' - 'a'], ret);
    return ret;
  }
};
