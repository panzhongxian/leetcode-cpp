#include "base.h"

typedef base::ListNode<int> ListNode;

class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {
    if (head == NULL || head->next == NULL) {
      return head;
    }
    ListNode* odd_list = head;
    ListNode* even_list = head->next;
    ListNode* cur_node = head;
    ListNode* next_node;
    ListNode* last_odd_node;
    bool is_odd_node = true;

    while (cur_node) {
      if (is_odd_node) {
        last_odd_node = cur_node;
      }
      is_odd_node = !is_odd_node;
      next_node = cur_node->next;
      cur_node->next = next_node ? next_node->next : NULL;
      cur_node = next_node;
    }
    last_odd_node->next = even_list;
    return odd_list;
  }
};
