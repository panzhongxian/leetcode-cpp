#include "0316_remove-duplicate-letters.h"

#include "base.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.removeDuplicateLetters("bcabc"), "abc");
  EXPECT_EQ(s.removeDuplicateLetters("dbcabc"), "dabc");
  EXPECT_EQ(s.removeDuplicateLetters("cbacdcbc"), "acdb");
}
