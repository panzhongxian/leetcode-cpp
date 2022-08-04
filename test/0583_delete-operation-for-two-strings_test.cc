#include "0583_delete-operation-for-two-strings.h"

#include "base.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.minDistance("a", "a"), 0);
  EXPECT_EQ(s.minDistance("eat", "tea"), 2);
  EXPECT_EQ(s.minDistance("intention", "execution"), 8);
}
