class Solution {
 public:
  string shiftingLetters(string s, vector<int>& shifts) {
    for (int i = shifts.size() - 1; i > 0; i--) {
      shifts[i - 1] += shifts[i] % 26;
    }
    for (int i = 0; i < shifts.size(); i++) {
      s[i] = (s[i] - 'a' + shifts[i]) % 26 + 'a';
    }
    return s;
  }
};
