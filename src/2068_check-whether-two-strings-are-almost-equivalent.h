class Solution {
public:
  bool checkAlmostEquivalent(string word1, string word2) {
    int m1[256] = {0};
    int m2[256] = {0};
    for (char c : word1) {
      m1[c] += 1;
    }
    for (char c : word2) {
      m2[c] += 1;
    }

    for (char c = 'a'; c <= 'z'; c++) {
      if (abs(m1[c] - m2[c]) > 3) {
        return false;
      }
    }
    return true;
  }
};
