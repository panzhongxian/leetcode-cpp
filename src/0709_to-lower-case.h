class Solution {
 public:
  string toLowerCase(string s) {
    constexpr int diff = 'A' - 'a';
    for (int i = 0; i < s.size(); i++) {
      if (s[i] <= 'Z' && s[i] >= 'A') s[i] = s[i] - diff;
    }
    return s;
  }
};
