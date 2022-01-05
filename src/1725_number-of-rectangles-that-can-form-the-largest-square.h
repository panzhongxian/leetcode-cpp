#include "base.h"

class Solution {
 public:
  int countGoodRectangles(vector<vector<int>>& rectangles) {
    int max_square_width = INT_MIN;
    int cnt = 0;
    for (auto v : rectangles) {
      int square_width = min(v[0], v[1]);
      if (square_width > max_square_width) {
        max_square_width = square_width;
        cnt = 1;
      } else if (square_width == max_square_width) {
        cnt++;
      }
    }
    return cnt;
  }
};
