#include "0005_longest-palindromic-substring.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.longestPalindrome(""), "");
  EXPECT_EQ(s.longestPalindrome("baba"), "bab");
  EXPECT_EQ(s.longestPalindrome("cbbd"), "bb");
  EXPECT_EQ(s.longestPalindrome("bb"), "bb");
  EXPECT_EQ(s.longestPalindrome("bbb"), "bbb");
  EXPECT_EQ(s.longestPalindrome("b"), "b");

  // execute s.Solve
}
