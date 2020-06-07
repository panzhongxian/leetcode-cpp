#include "0139_word-break.h"

TEST(S, Demo1) {
  Solution s;
  EXPECT_EQ(s.wordBreak("leetcode", {"leet", "code"}), true);
  EXPECT_EQ(s.wordBreak("applepenapple", {"apple", "pen"}), true);
  EXPECT_EQ(s.wordBreak("applepenapplee", {"apple", "pen"}), false);
  EXPECT_EQ(s.wordBreak("catsandog", {"cats", "dog", "sand", "and", "cat"}),
            false);
}
