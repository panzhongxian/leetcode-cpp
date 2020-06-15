#include "0480_sliding-window-median.h"

TEST(S, Demo) {
  Solution s;
  cout << s.medianSlidingWindow({1, 3, -1, -3, 5, 3, 6, 7}, 3) << endl;
  cout << s.medianSlidingWindow({1, 3, 2, 2, 3, 1}, 4) << endl;
  cout << s.medianSlidingWindow({1, 3, -1, -3, 5, 3, 6, 7}, 4) << endl;
}
