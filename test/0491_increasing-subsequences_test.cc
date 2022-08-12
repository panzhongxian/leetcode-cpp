#include "0491_increasing-subsequences.h"

#include "base.h"

TEST(S, Demo) {
  Solution s;

  auto ret = s.findSubsequences({4, 6, 4, 7, 7});
  for (auto& v : ret) {
    for (int n : v) {
      cout << n << " ";
    }
    cout << endl;
  }
}
