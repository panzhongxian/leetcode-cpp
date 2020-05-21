#include "0002_add_two_numbers.h"

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(ListNode::Dump(s.addTwoNumbers(ListNode::Factory({1, 2, 4}),
                                           ListNode::Factory({1, 2, 4}))),
            vector<int>({2, 4, 8}));

  EXPECT_EQ(ListNode::Dump(s.addTwoNumbers(ListNode::Factory({1, 2, 6}),
                                           ListNode::Factory({1, 2, 4}))),
            vector<int>({2, 4, 0, 1}));

  EXPECT_EQ(
      ListNode::Dump(s.addTwoNumbers(ListNode::Factory({1, 2, 6}), nullptr)),
      vector<int>({1, 2, 6}));

  EXPECT_EQ(ListNode::Dump(s.addTwoNumbers(ListNode::Factory({1, 2, 6}), {0})),
            vector<int>({1, 2, 6}));

  EXPECT_EQ(ListNode::Dump(s.addTwoNumbers(nullptr, nullptr)), vector<int>());
}
