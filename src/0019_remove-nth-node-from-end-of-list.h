#include "base.h"

typedef base::ListNode<int> ListNode;

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* fake_head = new ListNode;
    fake_head->next = head;
    ListNode* p0 = fake_head;
    ListNode* p1 = p0;
    for (size_t i = 0; i < n && p1; i++) {
      p1 = p1->next;
    }
    if (!p1) {
      return p0->next;
    }

    while (p1->next) {
      p0 = p0->next;
      p1 = p1->next;
    }

    p1 = p0->next;
    p0->next = p0->next->next;
    delete (p1);
    return fake_head->next;
  }
};
