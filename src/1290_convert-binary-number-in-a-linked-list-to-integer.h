#include "base.h"
typedef base::ListNode<int> ListNode;

class Solution {
 public:
  int getDecimalValue(ListNode* head) {
    int ret = 0;
    while (head) {
      ret <<= 1;
      if (head->val) {
        ret += 1;
      }
      head = head->next;
    }
    return ret;
  }
};
