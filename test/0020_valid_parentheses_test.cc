#include "0020_valid_parentheses.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.isValid(""), true);
  EXPECT_EQ(s.isValid("[]"), true);
  EXPECT_EQ(s.isValid("[(]])]"), false);
  EXPECT_EQ(s.isValid("[(]])]"), false);
  EXPECT_EQ(s.isValid("{}"), true);
  EXPECT_EQ(s.isValid("]{[}"), false);
  EXPECT_EQ(s.isValid("){[}"), false);
  EXPECT_EQ(s.isValid("[)"), false);
}
