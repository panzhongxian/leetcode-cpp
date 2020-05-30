#include "0560_subarray-sum-equals-k.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.subarraySum(vector<int>({1, 1, 1, 0, 1}), 4), 1);
  EXPECT_EQ(s.subarraySum(vector<int>({0, 0, 0, 0, 0}), 0), 15);
}
