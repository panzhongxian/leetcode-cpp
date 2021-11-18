#include "0686_repeated-string-match.h"

#include "base.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.repeatedStringMatch("abcd", "cdabcdab"), 3);
  EXPECT_EQ(s.repeatedStringMatch("a", "aa"), 2);
  EXPECT_EQ(s.repeatedStringMatch("a", "a"), 1);
  EXPECT_EQ(s.repeatedStringMatch("abc", "wxyz"), -1);
  EXPECT_EQ(s.repeatedStringMatch("", "w"), -1);
  EXPECT_EQ(s.repeatedStringMatch("a", ""), 0);
  EXPECT_EQ(s.repeatedStringMatch("aaaaaab", "ba"), 2);
  EXPECT_EQ(s.repeatedStringMatch("abcd", "bcdab"), 2);
}
