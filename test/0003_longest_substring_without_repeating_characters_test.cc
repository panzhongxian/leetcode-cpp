#include "0003_longest_substring_without_repeating_characters.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.lengthOfLongestSubstring("abcba"), 3);
  EXPECT_EQ(s.lengthOfLongestSubstring("abcd"), 4);
  EXPECT_EQ(s.lengthOfLongestSubstring("abca"), 3);
  EXPECT_EQ(s.lengthOfLongestSubstring("aaaaa"), 1);
  EXPECT_EQ(s.lengthOfLongestSubstring("a"), 1);
}
