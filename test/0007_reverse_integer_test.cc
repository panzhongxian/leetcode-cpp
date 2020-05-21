#include "0007_reverse_integer.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.reverse(0), 0);
  EXPECT_EQ(s.reverse(2147483642), 0);
  EXPECT_EQ(s.reverse(-2147483642), 0);
  EXPECT_EQ(s.reverse(2147447412), 2147447412);
  EXPECT_EQ(s.reverse(-2147447412), -2147447412);
  EXPECT_EQ(s.reverse(1234), 4321);
  EXPECT_EQ(s.reverse(-1234), -4321);
}
