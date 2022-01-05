#include "base.h"
typedef base::ListNode<int> ListNode;

class Solution {
 public:
  void deleteNode(ListNode* node) {
    assert(node);
    assert(node->next);

    node->val = node->next->val;
    auto p = node->next->next;
    delete node->next;
    node->next = p;
  }
};
