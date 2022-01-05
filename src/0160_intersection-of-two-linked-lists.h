#include "base.h"
typedef base::ListNode<int> ListNode;

class Solution {
 public:
  static int MeasureListLength(ListNode* head) {
    int len = 0;
    ListNode* p = head;
    while (p) {
      len++;
      p = p->next;
    }
    return len;
  }

  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    int len_a = MeasureListLength(headA);
    int len_b = MeasureListLength(headB);
    if (len_a < len_b) {
      swap(headA, headB);
      swap(len_a, len_b);
    }

    while (len_a > len_b) {
      headA = headA->next;
      len_a--;
    }

    while (len_a > 0) {
      if (headA == headB) {
        return headA;
      }
      headA = headA->next;
      headB = headB->next;
      len_a--;
    }
    return nullptr;
  }
};
