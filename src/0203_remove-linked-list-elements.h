#include "base.h"
typedef base::ListNode<int> ListNode;

class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* fake_head = new ListNode;
    fake_head->next = head;
    ListNode* pre_node = fake_head;
    while (pre_node->next) {
      if (pre_node->next->val == val) {
        pre_node->next = pre_node->next->next;
      } else {
        pre_node = pre_node->next;
      }
    }
    return fake_head->next;
  }
};
