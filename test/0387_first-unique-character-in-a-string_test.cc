#include "0387_first-unique-character-in-a-string.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.firstUniqChar("leetcode"), 0);
  EXPECT_EQ(s.firstUniqChar("loveleetcode"), 2);
  EXPECT_EQ(s.firstUniqChar("aabbccddd"), -1);
}
