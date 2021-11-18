#include "0859_buddy-strings.h"

#include "base.h"

TEST(S, Demo) {
  Solution s;

  EXPECT_EQ(s.buddyStrings("ab", "ba"), true);
  EXPECT_EQ(s.buddyStrings("ab", "ab"), false);
  EXPECT_EQ(s.buddyStrings("aa", "aa"), true);
  EXPECT_EQ(s.buddyStrings("aaaaaaabc", "aaaaaaacb"), true);
  EXPECT_EQ(s.buddyStrings("aaaaaaabc", "aaaaaaacd"), false);
}
