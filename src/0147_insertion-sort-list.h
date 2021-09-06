/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include "base.h"
typedef base::ListNode<int> ListNode;

class Solution {
 public:
  ListNode* insertionSortList(ListNode* head) {
    ListNode* ret = NULL;
    while (head) {
      ListNode* cur_node = head;
      head = head->next;
      ret = InsertSingleNode(ret, cur_node);
    }
    return ret;
  }

  ListNode* InsertSingleNode(ListNode* sorted_list, ListNode* node) {
    assert(node);
    node->next = NULL;
    if (!sorted_list) {
      return node;
    }

    if (node->val < sorted_list->val) {
      node->next = sorted_list;
      return node;
    }

    ListNode* ret = sorted_list;
    while (sorted_list->next) {
      if (node->val > sorted_list->next->val) {
        sorted_list = sorted_list->next;
        continue;
      }
      node->next = sorted_list->next;
      sorted_list->next = node;
      return ret;
    }

    sorted_list->next = node;
    return ret;
  }
};
