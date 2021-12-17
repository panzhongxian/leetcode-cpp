class Solution {
 public:
  int countBinarySubstrings(string s) {
    int ret = 0;
    int prev_len = 0;
    int cur_len = 1;
    char cur_char = s[0];
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == cur_char) {
        cur_len++;
      } else {
        if (prev_len > 0) {
          ret += min(prev_len, cur_len);
        }
        prev_len = cur_len;
        cur_len = 1;
        cur_char = s[i];
      }
    }
    if (prev_len > 0) {
      ret += min(prev_len, cur_len);
    }

    return ret;
  }
};
