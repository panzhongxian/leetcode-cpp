#include "0008_string_to_integer.h"

TEST(S, Demo) {
  Solution s;
#define test(x) EXPECT_EQ(s.myAtoi(x), atoi(x))
  test("   ");
  test("2147483647");
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
