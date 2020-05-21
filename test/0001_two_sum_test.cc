#include "0001_two_sum.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.twoSum(vector<int>({1, 2, 3, 4}), 4), vector<int>({0, 2}));
  EXPECT_EQ(s.twoSum(vector<int>({1, 2, 3, 4}), 9), vector<int>());
  EXPECT_EQ(s.twoSum(vector<int>({1, 2, 3, 4}), 5), vector<int>({1, 2}));
}
