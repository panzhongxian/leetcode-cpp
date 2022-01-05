#include "base.h"

class Solution {
 public:
  int i = 0;
  int j = 0;
  bool judgeCircle(string moves) {
    for (char c : moves) {
      switch (c) {
        case 'L':
          i++;
          break;
        case 'R':
          i--;
          break;
        case 'D':
          j++;
          break;
        case 'U':
          j--;
          break;
      }
    }
    return i == 0 && j == 0;
  }
};
