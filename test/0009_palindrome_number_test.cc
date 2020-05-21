#include "0009_palindrome_number.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.isPalindrome(0), true);
  EXPECT_EQ(s.isPalindrome(2147483642), false);
  EXPECT_EQ(s.isPalindrome(-2147483642), false);
  EXPECT_EQ(s.isPalindrome(2147447412), true);
  EXPECT_EQ(s.isPalindrome(1234), false);
  EXPECT_EQ(s.isPalindrome(1234321), true);
  EXPECT_EQ(s.isPalindrome(12344321), true);
  EXPECT_EQ(s.isPalindrome(10), false);
  EXPECT_EQ(s.isPalindrome(100), false);
  EXPECT_EQ(s.isPalindrome(1000), false);
  EXPECT_EQ(s.isPalindrome(1001), true);
  EXPECT_EQ(s.isPalindrome(10001), true);
}
