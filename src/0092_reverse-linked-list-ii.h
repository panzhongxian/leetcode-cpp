#include "base.h"

typedef base::ListNode<int> ListNode;

class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head || left == right) {
      return head;
    }

    ListNode* ret = new ListNode;
    ret->next = head;
    ListNode* cur_node = ret;
    ListNode* node_before_left;

    int idx = 0;
    while (cur_node->next) {
      idx++;
      if (idx == left) {
        node_before_left = cur_node;
        cur_node = cur_node->next;
        break;
      }
      cur_node = cur_node->next;
    }

    ListNode* next_node = cur_node->next;
    ListNode* next_next_node;
    // now cur_node is left node

    while (next_node) {
      idx++;
      next_next_node = next_node->next;
      next_node->next = cur_node;
      if (idx == right) {
        node_before_left->next->next = next_next_node;
        node_before_left->next = next_node;
        return ret->next;
      }

      cur_node = next_node;
      next_node = next_next_node;
    }
    return ret->next;
  }
};
