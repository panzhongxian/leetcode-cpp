#include "1143_longest-common-subsequence.h"
TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.longestCommonSubsequence("", "abc"), 0);
  EXPECT_EQ(s.longestCommonSubsequence("abc", "abc"), 3);
  EXPECT_EQ(s.longestCommonSubsequence("aebfc", "abc"), 3);
  EXPECT_EQ(s.longestCommonSubsequence("cba", "abc"), 1);
  EXPECT_EQ(s.longestCommonSubsequence("bl", "yby"), 1);
}
