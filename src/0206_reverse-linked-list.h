#include "base.h"

typedef base::ListNode<int> ListNode;

// iteratively
class Solution1 {
 public:
  ListNode* reverseList(ListNode* head) {
    if (!head) {
      return nullptr;
    }
    ListNode* prev = nullptr;
    ListNode* cur = head;
    ListNode* next;
    while (cur) {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    return prev;
  }
};

// recursively
class Solution2 {
 public:
  ListNode* recursiveInsertReverseList(ListNode* head, ListNode** tail) {
    if (head->next == nullptr) {
      *tail = head;
      return head;
    }

    ListNode* tmp;
    ListNode* ret = recursiveInsertReverseList(head->next, &tmp);
    tmp->next = head;
    *tail = head;
    return ret;
  }

  ListNode* reverseList(ListNode* head) {
    if (!head) {
      return nullptr;
    }
    ListNode* tail;
    ListNode* ret = recursiveInsertReverseList(head, &tail);
    tail->next = nullptr;
    return ret;
  }
};
