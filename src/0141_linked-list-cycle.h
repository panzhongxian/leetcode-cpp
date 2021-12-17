#include "base.h"

typedef base::ListNode<int> ListNode;

class Solution {
 public:
  bool hasCycle(ListNode* head) {
    if (head == nullptr) {
      return false;
    }

    ListNode* fake_head = new ListNode;
    fake_head->next = head;
    ListNode* p1 = fake_head;
    ListNode* p2 = fake_head;

    size_t diff = 0;
    do {
      p2 = p2->next;
      if (p2 == p1) {
        return true;
      }

      if (p2 == nullptr) {
        return false;
      }

      p2 = p2->next;
      p1 = p1->next;
      if (p2 == p1) {
        return true;
      }
    } while (p1 && p2);

    return false;
  }
};
