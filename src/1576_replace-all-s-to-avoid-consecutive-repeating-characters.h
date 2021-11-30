class Solution {
public:
  char get_not_same_char(char c) {
    if (c == '?') {
      return 'a';
    }
    char ret = 'a';
    while (ret == c) {
      ret++;
    }
    return ret;
  }
  char get_not_same_char(char c1, char c2) {
    char ret = get_not_same_char(c1);
    if (c2 == '?') {
      return ret;
    }
    while (ret == c2 || ret == c1) {
      ret++;
    }
    return ret;
  }

  string modifyString(string s) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != '?') {
        continue;
      }
      if (i == 0) {
        s[i] = get_not_same_char(s[i + 1]);
      } else if (i == (s.size() - 1)) {
        s[i] = get_not_same_char(s[i - 1]);
      } else {
        s[i] = get_not_same_char(s[i - 1], s[i + 1]);
      }
    }
    return s;
  }
};
