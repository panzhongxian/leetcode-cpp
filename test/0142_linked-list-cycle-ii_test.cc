#include "0142_linked-list-cycle-ii.h"

ListNode* CreateLinkedListCircle(int pos) {
  auto head = ListNode::Factory({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
  auto end = head;
  ListNode* circle_head = nullptr;
  int cur_pos = 0;
  while (end->next) {
    if (cur_pos == pos) {
      circle_head = end;
    }
    end = end->next;
    cur_pos++;
  }

  if (cur_pos == pos) {
    circle_head = end;
  }
  end->next = circle_head;
  return head;
}

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(nullptr, s.detectCycle(CreateLinkedListCircle(-1)));
  for (int i = 0; i < 10; ++i) {
    auto l = CreateLinkedListCircle(i);
    EXPECT_EQ(i, s.detectCycle(l)->val);
  }
}
