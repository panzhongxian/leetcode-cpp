#include "base.h"

typedef base::ListNode<int> ListNode;

class Solution {
 public:
  ListNode* mergeList(ListNode* h1, ListNode* h2) {
    ListNode* fake_ret = new ListNode;
    ListNode* cur_ptr = fake_ret;

    while (h1 && h2) {
      if (h1->val < h2->val) {
        cur_ptr->next = h1;
        h1 = h1->next;
      } else {
        cur_ptr->next = h2;
        h2 = h2->next;
      }
      cur_ptr = cur_ptr->next;
    }

    if (h1) {
      cur_ptr->next = h1;
    } else {
      cur_ptr->next = h2;
    }

    return fake_ret->next;
  }

  ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode* h1 = new ListNode;
    ListNode* h2 = new ListNode;
    ListNode* p1 = h1;
    ListNode* p2 = h2;
    p1->next = head;
    p2->next = head;

    while (p2->next) {
      p2 = p2->next;
      p1 = p1->next;
      if (p2->next == nullptr) {
        break;
      }
      p2 = p2->next;
    }

    p2 = p1->next;
    p1->next = nullptr;

    p1 = sortList(head);
    p2 = sortList(p2);
    return mergeList(p1, p2);
  }
};
