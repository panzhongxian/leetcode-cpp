#include "0322_coin-change.h"
TEST(S, Demo) {
  Solution s;
  {
    vector<int> v({1, 2, 5});
    cout << s.coinChange(v, 11) << endl;
  }
  {
    vector<int> v({1, 2147483647});
    cout << s.coinChange(v, 2) << endl;
  }
  {
    vector<int> v({1, 3, 5});
    cout << s.coinChange(v, 7) << endl;
  }
}
