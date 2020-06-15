#include "0148_sort-list.h"

TEST(S, Demo1) {
  Solution s;
  auto l = ListNode::Factory({4, 2, 1, 3});
  l = s.sortList(l);
  EXPECT_EQ(ListNode::Dump(l), vector<int>({1, 2, 3, 4}));
}
TEST(S, Demo2) {
  Solution s;
  auto l = ListNode::Factory({-1, 5, 3, 4, 0});
  l = s.sortList(l);
  EXPECT_EQ(ListNode::Dump(l), vector<int>({-1, 0, 3, 4, 5}));
}
