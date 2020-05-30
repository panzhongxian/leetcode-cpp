#include "0525_contiguous-array.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.findMaxLength(vector<int>({0})), 0);
  EXPECT_EQ(s.findMaxLength(vector<int>({1})), 0);
  EXPECT_EQ(s.findMaxLength(vector<int>({1, 1})), 0);
  EXPECT_EQ(s.findMaxLength(vector<int>({0, 0})), 0);
  EXPECT_EQ(s.findMaxLength(vector<int>({0, 1})), 2);
  EXPECT_EQ(s.findMaxLength(vector<int>({0, 0, 1, 1})), 4);
  EXPECT_EQ(s.findMaxLength(vector<int>({0, 0, 1, 0})), 2);
  EXPECT_EQ(s.findMaxLength(vector<int>({0, 1, 1, 1})), 2);
}
