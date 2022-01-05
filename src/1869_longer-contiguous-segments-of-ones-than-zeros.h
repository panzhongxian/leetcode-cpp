#include "base.h"

class Solution {
 public:
  bool checkZeroOnes(string s) {
    if (s.empty()) {
      return false;
    } else {
      s.push_back(s[s.size() - 1] == '0' ? '1' : '0');
    }

    int max_cnt[2] = {0};
    int curr_cnt[2] = {0};
    // i: self index, j: opposite index
    int i, j;
    for (char c : s) {
      i = c - '0';
      j = i ^ 1;
      if (curr_cnt[j] > 0) {
        if (curr_cnt[j] > max_cnt[j]) {
          max_cnt[j] = curr_cnt[j];
        }
        curr_cnt[j] = 0;
      }
      curr_cnt[i]++;
    }
    return max_cnt[1] > max_cnt[0];
  }
};
