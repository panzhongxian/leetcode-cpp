#include "base.h"
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int i = 0;
    int j = 0;
    int ret = 0;
    unordered_map<int, int> elem_idx;

    while (j < (int)s.length()) {
      if (!elem_idx.count(s[j]) || elem_idx[s[j]] == -1) {
        elem_idx[s[j]] = j;
        j++;
        continue;
      }

      ret = max(ret, j - i);
      int next_i = elem_idx[s[j]] + 1;
      for (; i < next_i; ++i) {
        s[i] = -1;
      }
      elem_idx[s[j]] = j;
      j++;
    }

    ret = max(ret, j - i);
    return ret;
  }
};
