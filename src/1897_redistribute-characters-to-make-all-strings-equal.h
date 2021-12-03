class Solution {
public:
  bool makeEqual(vector<string> &words) {
    int m[26];
    memset(m, 0, 26 * sizeof(int));
    for (auto &word : words) {
      for (char c : word) {
        m[c - 'a']++;
      }
    }
    for (int i = 0; i < 26; i++) {
      if (m[i] % words.size() != 0) {
        return false;
      }
    }
    return true;
  }
};
