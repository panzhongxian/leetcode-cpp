#include "base.h"

typedef base::ListNode<int> ListNode;

class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    ListNode* fake_head = new ListNode(0);
    fake_head->next = head;
    ListNode* p0 = fake_head;
    ListNode* p1;
    ListNode* p2;
    while (p0) {
      p1 = p0->next;
      if (!p1) return fake_head->next;
      p2 = p1->next;
      if (!p2) return fake_head->next;

      p0->next = p2;
      p1->next = p2->next;
      p2->next = p1;
      p0 = p1;
    }
    return fake_head->next;
  }
};
