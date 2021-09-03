#include "base.h"

typedef base::ListNode<int> ListNode;

class Solution {
 public:
  ListNode *partition(ListNode *head, int x) {
    ListNode *left_head = new ListNode;
    ListNode *right_head = new ListNode;
    ListNode *left_tail = left_head;
    ListNode *right_tail = right_head;

    while (head) {
      if (head->val < x) {
        if (left_tail->next != head) {
          left_tail->next = head;
        }
        head = head->next;
        left_tail = left_tail->next;
      } else {
        if (right_tail->next != head) {
          right_tail->next = head;
        }
        head = head->next;
        right_tail = right_tail->next;
      }
    }
    left_tail->next = NULL;
    right_tail->next = NULL;

    left_head = left_head->next;
    right_head = right_head->next;
    if (left_head) {
      left_tail->next = right_head;
      return left_head;
    }

    return right_head;
  }
};
