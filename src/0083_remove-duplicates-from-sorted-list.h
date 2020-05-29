#include "base.h"

typedef base::ListNode<int> ListNode;

class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* fake_head_ptr = new ListNode;
    fake_head_ptr->next = head;
    ListNode* p1 = head;
    ListNode* p2 = head;

    while (p1) {
      p2 = p1;
      while (p2 && p2->val == p1->val) {
        p2 = p2->next;
      }
      p1->next = p2;
      p1 = p1->next;
    }
    return fake_head_ptr->next;
  }
};
