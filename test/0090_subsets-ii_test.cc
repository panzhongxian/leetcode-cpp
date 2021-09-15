#include "0090_subsets-ii.h"

#include "base.h"

TEST(S, Demo) {
  Solution s;
  vector<vector<int>> expected_ret = {{}, {1}, {1, 2}, {1, 2, 2}, {2}, {2, 2}};
  auto result = s.subsetsWithDup({1, 2, 2});
  sort(result.begin(), result.end());
  sort(expected_ret.begin(), expected_ret.end());
  EXPECT_EQ(result, expected_ret) << endl;
}
