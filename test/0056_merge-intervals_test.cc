#include "0056_merge-intervals.h"

TEST(S, Demo1) {
  Solution s;
  vector<vector<int>> v{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  cout << s.merge(v) << endl;
}

TEST(S, Demo2) {
  Solution s;
  vector<vector<int>> v{{1, 4}, {4, 5}};
  cout << s.merge(v) << endl;
}
