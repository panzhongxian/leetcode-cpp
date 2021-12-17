class Solution {
 public:
  string replaceDigits(string s) {
    string ret;
    for (int i = 0; i < s.size(); i += 2) {
      ret.push_back(s[i]);
      if (i + 1 < s.size()) {
        ret.push_back(s[i] + s[i + 1] - '0');
      }
    }
    return ret;
  }
};
