#include "1415_the-k-th-lexicographical-string-of-all-happy-strings-of-length-n.h"

#include "base.h"
TEST(Solution, Demo) {
  Solution s;
  EXPECT_EQ(s.getHappyString(3, 1), "aba");
  EXPECT_EQ(s.getHappyString(3, 2), "abc");
  EXPECT_EQ(s.getHappyString(3, 12), "cbc");
  EXPECT_EQ(s.getHappyString(3, 13), "");
}
