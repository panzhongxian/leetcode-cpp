#include "base.h"

class Solution {
 public:
  int countConsistentStrings(string allowed, vector<string>& words) {
    int ret = 0;
    int m[256] = {0};
    for (char c : allowed) {
      m[c] = 1;
    }
    for (auto& word : words) {
      bool allowed_flag = true;
      for (char c : word) {
        if (m[c] != 1) {
          allowed_flag = false;
        }
      }
      if (allowed_flag) {
        ret++;
      }
    }
    return ret;
  }
};
