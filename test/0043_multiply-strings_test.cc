#include "0043_multiply-strings.h"

#include "base.h"

TEST(S, Demo) {
  Solution s;
  ASSERT_EQ(s.multiply("2", "3"), "6");
  ASSERT_EQ(s.multiply("123", "456"), "56088");
  ASSERT_EQ(s.multiply("0", "52"), "0");
}
