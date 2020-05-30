#include "base.h"

typedef base::ListNode<int> ListNode;

class Solution {
 public:
  ListNode* middleNode(ListNode* head) {
    ListNode* fake_head = new ListNode;
    fake_head->next = head;
    ListNode* p1 = fake_head;
    ListNode* p2 = fake_head;
    while (p1 && p2) {
      p1 = p1->next;
      p2 = p2->next;
      if (!p2) {
        return p1;
      }
      p2 = p2->next;
    }
    return p1;
  }
};
