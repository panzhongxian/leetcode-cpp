#include "base.h"

typedef base::ListNode<int> ListNode;

class Solution {
 public:
  int CalcLength(ListNode* head) {
    int len = 0;
    while (head->next) {
      len++;
      head = head->next;
    }
    return len;
  }

  ListNode* detectCycle(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }

    ListNode* fake_head_1 = new ListNode(0);
    fake_head_1->next = head;
    ListNode* p1 = fake_head_1;
    ListNode* p2 = fake_head_1;

    do {
      p2 = p2->next;
      if (p2 == p1) {
        break;
      }

      if (p2 == nullptr) {
        return nullptr;
      }

      p2 = p2->next;
      p1 = p1->next;
      if (p2 == p1) {
        break;
      }
    } while (p1 && p2);

    if (!p1 || !p2) {
      return nullptr;
    }

    // p1 == p2 && p1 != nullptr
    if (p1->next == p1) {
      return p1;
    }

    ListNode* new_head = p1->next;
    p1->next = nullptr;

    int len1 = CalcLength(head);
    int len2 = CalcLength(new_head);
    if (len1 < len2) {
      swap(head, new_head);
      swap(len1, len2);
    }

    for (int i = 0; i < len1 - len2; ++i) {
      head = head->next;
    }

    while (head != new_head) {
      head = head->next;
      new_head = new_head->next;
    }
    return head;
  }
};
