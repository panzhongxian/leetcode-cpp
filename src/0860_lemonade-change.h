#include "base.h"

class Solution {
 public:
  bool lemonadeChange(vector<int>& bills) {
    int five = 0;
    int ten = 0;
    for (int bill : bills) {
      switch (bill) {
        case 5:
          five++;
          break;
        case 10:
          if (five == 0) {
            return false;
          }
          five--;
          ten++;
          break;
        case 20:
          if (ten == 0) {
            five -= 3;
          } else {
            ten--;
            five--;
          }
          break;
      }

      if (five < 0) {
        return false;
      }
    }
    return true;
  }
};
