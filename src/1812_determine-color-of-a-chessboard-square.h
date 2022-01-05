#include "base.h"

class Solution {
 public:
  bool squareIsWhite(string coordinates) {
    bool c1 = (coordinates[0] - 'a') & 1;
    bool c2 = (coordinates[1] - '1') & 1;
    return c1 != c2;
  }
};
