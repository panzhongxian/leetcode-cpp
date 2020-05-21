#include "base.h"
typedef base::ListNode<int> ListNode;
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* ret;
    ListNode** prev_next_ptr = &ret;

    while (l1 && l2) {
      if (l1->val < l2->val) {
        *prev_next_ptr = l1;
        l1 = l1->next;
      } else {
        *prev_next_ptr = l2;
        l2 = l2->next;
      }
      prev_next_ptr = &((*prev_next_ptr)->next);
    }
    *prev_next_ptr = l1 ? l1 : l2;
    return ret;
  }
};
