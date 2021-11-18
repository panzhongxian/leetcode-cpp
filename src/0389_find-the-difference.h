class Solution {
 public:
  char findTheDifference(string s, string t) {
    char m[128] = {0};
    for (char c : s) {
      m[c]++;
    }

    for (char c : t) {
      m[c]--;
    }
    for (int i = 'a'; i <= 'z'; i++) {
      if (m[i]) {
        return i;
      }
    }
    return 'a';
  }
};
