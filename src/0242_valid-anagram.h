#include "base.h"

#define ARR_SIZE 26

class Solution {
 public:
  void statistic_char(const string& s, int* m) {
    memset(m, 0, ARR_SIZE * sizeof(int));
    for (char c : s) {
      m[c - 'a']++;
    }
  }
  bool isAnagram(string s, string t) {
    int m1[ARR_SIZE];
    int m2[ARR_SIZE];
    statistic_char(s, m1);
    statistic_char(t, m2);
    for (int i = 0; i < ARR_SIZE; ++i) {
      if (m1[i] != m2[i]) {
        return false;
      }
    }
    return true;
  }
};
