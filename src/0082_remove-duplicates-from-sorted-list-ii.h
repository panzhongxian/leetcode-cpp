#include "base.h"

typedef base::ListNode<int> ListNode;

class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* fake_head_ptr = new ListNode;
    fake_head_ptr->next = head;
    ListNode* p0 = fake_head_ptr;
    ListNode* p1 = head;
    ListNode* p2 = head;

    while (p1) {
      p2 = p1;
      int cnt = 0;
      while (p2 && p2->val == p1->val) {
        cnt += 1;
        p2 = p2->next;
      }
      if (cnt == 1) {
        p0->next = p1;
        p0 = p0->next;
      }
      p1->next = p2;
      p1 = p1->next;
    }
    p0->next = nullptr;
    return fake_head_ptr->next;
  }
};
