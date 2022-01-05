#include "base.h"

class Solution {
 public:
  bool checkRecord(string s) {
    int a_cnt = 0;
    int l_continous_cnt = 0;
    for (char c : s) {
      switch (c) {
        case 'A':
          a_cnt++;
          l_continous_cnt = 0;
          break;
        case 'L':
          l_continous_cnt++;
          break;
        case 'P':
          l_continous_cnt = 0;
          break;
      }
      if (a_cnt == 2 || l_continous_cnt == 3) {
        return false;
      }
    }
    return true;
  }
};
