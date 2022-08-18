#include "1208_get-equal-substrings-within-budget.h"

#include "base.h"

TEST(Solution, Demo) {
  Solution s;
  EXPECT_EQ(s.equalSubstring("abcd", "bcdf", 3), 3);
  EXPECT_EQ(s.equalSubstring("abcd", "bcqe", 3), 2);
  EXPECT_EQ(s.equalSubstring("abcd", "abcd", 0), 4);
}
