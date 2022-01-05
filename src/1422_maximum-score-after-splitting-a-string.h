#include "base.h"

class Solution {
 public:
  int maxScore(string s) {
    int left_score = (s[0] == '0');
    int right_score = 0;
    for (size_t i = 1; i < s.size(); ++i) {
      if (s[i] == '1') {
        right_score++;
      }
    }

    int ret = left_score + right_score;
    for (size_t i = 1; i < s.size() - 1; ++i) {
      if (s[i] == '0') {
        left_score++;
      } else {
        right_score--;
      }
      if (left_score + right_score > ret) {
        ret = left_score + right_score;
      }
    }
    return ret;
  }
};
