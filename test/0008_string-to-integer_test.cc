#include "0008_string-to-integer.h"

TEST(S, Demo) {
  Solution s;
#define test(x) EXPECT_EQ(s.myAtoi(x), atoi(x))
  test("   ");
  test("2147483647");
  EXPECT_EQ(s.myAtoi("-2147483649"), -2147483648);
  EXPECT_EQ(s.myAtoi("2147483648"), 2147483647);
  test("-2147483648");
  test(" 1234");
  test(" 01234");
  test(" -123");
  test(" +123");
  test(" 1234abc");
  test(" -123abc");
  test(" +123abc");
  test("abcd");
  test(" abc");
}
