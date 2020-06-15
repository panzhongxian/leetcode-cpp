#include "0075_sort-colors.h"

TEST(S, Demo1) {
  Solution s;
  vector<int> v{2, 0, 2, 1, 1, 0};
  s.sortColors(v);
  cout << v << endl;
  ;
}
TEST(S, Demo2) {
  Solution s;
  vector<int> v{2, 0, 1};
  s.sortColors(v);
  cout << v << endl;
  ;
}
