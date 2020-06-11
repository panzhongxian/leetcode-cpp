#include "0234_palindrome-linked-list.h"
TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.isPalindrome(ListNode::Factory({1})), true);
  EXPECT_EQ(s.isPalindrome(ListNode::Factory({1, 1})), true);
  EXPECT_EQ(s.isPalindrome(ListNode::Factory({1, 2, 4})), false);
  EXPECT_EQ(s.isPalindrome(ListNode::Factory({1, 2, 4, 2, 1})), true);
}
