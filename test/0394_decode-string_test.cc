#include "0394_decode-string.h"

#include "base.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.decodeString("a"), "a");
  EXPECT_EQ(s.decodeString("1[abc]d"), "abcd");
  EXPECT_EQ(s.decodeString("2[abc]d"), "abcabcd");
  EXPECT_EQ(s.decodeString("3[a]2[bc]"), "aaabcbc");
  EXPECT_EQ(s.decodeString("3[a2[bc]]2[bc]"), "abcbcabcbcabcbcbcbc");
}
