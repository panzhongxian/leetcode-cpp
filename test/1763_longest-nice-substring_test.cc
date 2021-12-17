#include "1763_longest-nice-substring.h"

TEST(Solution, Demo) {
  Solution s;
  EXPECT_EQ(s.longestNiceSubstring("DbaAaCg"), "aAa");
  EXPECT_EQ(s.longestNiceSubstring("dDzeE"), "dD");
  EXPECT_EQ(s.longestNiceSubstring("dDzZeE"), "dDzZeE");
}
