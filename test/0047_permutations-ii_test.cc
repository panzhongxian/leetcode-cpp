#include "0047_permutations-ii.h"

using namespace base;

TEST(S, Demo) {
  Solution s;
  cout << s.permuteUnique({1, 2, 3}) << endl;
  cout << s.permuteUnique({1, 1, 2}) << endl;
  cout << s.permuteUnique({1, 1, 2, 2}) << endl;
  cout << s.permuteUnique({0, 1, 0, 0, 9}).size() << endl;
  cout << s.permuteUnique({-1, 2, 0, -1, 1, 0, 1}).size() << endl;
}
