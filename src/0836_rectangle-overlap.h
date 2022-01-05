#include "base.h"

class Solution {
 public:
  bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    return !(                  //
        rec1[1] >= rec2[3] ||  // up
        rec1[2] <= rec2[0] ||  // left
        rec1[3] <= rec2[1] ||  // down
        rec1[0] >= rec2[2]     // right
    );
  }
};
