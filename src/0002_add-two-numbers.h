#include "base.h"
typedef base::ListNode<int> ListNode;

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (!l1 && !l2) {
      return nullptr;
    }

    ListNode *p1, *p2, *cur;
    p1 = l1;
    p2 = l2;

    ListNode* ret = new ListNode(0);
    cur = ret;

    int carry = 0;
    while (p1 && p2) {
      cur->next = new ListNode(0);
      cur = cur->next;
      int cur_digit = p1->val + p2->val + carry;
      cur->val = cur_digit % 10;
      carry = cur_digit / 10;
      p1 = p1->next;
      p2 = p2->next;
    }

    ListNode* p = p1 ? p1 : p2;
    while (p) {
      cur->next = new ListNode(0);
      cur = cur->next;
      int cur_digit = p->val + carry;
      cur->val = cur_digit % 10;
      carry = cur_digit / 10;
      p = p->next;
    }

    if (carry) {
      cur->next = new ListNode(1);
    }

    return ret->next;
  }
};
