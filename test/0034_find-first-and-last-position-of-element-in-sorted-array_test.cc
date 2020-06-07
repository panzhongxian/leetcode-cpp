#include "0034_find-first-and-last-position-of-element-in-sorted-array.h"
TEST(S, Demo) {
  for (int i = 0; i < 7; ++i) {
    Solution s;
    cout << s.searchRange({1, 2, 3, 4, 5}, i) << endl;
  }

  Solution s;
  cout << s.searchRange({5, 7, 7, 8, 8, 10}, 8) << endl;
  cout << s.searchRange({8, 8}, 8) << endl;
}
