#include "0039_combination-sum.h"

using base::operator<<;

TEST(S, Demo) {
  Solution s;
  cout << s.combinationSum({2, 3, 6, 7}, 6) << endl;
  cout << s.combinationSum({2, 3, 6, 7}, 7) << endl;
}
