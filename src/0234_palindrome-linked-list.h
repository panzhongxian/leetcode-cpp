#include "base.h"

typedef base::ListNode<int> ListNode;
class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    if (!head) {
      return true;
    }
    vector<ListNode*> s;
    ListNode* p1 = head;
    ListNode* p2 = head;
    if (p2->next == nullptr) {
      return true;
    }
    p2 = p2->next;
    s.push_back(p1);
    while (p2->next) {
      p2 = p2->next;
      if (p2->next == nullptr) {
        p1 = p1->next;
        break;
      }
      p1 = p1->next;
      p2 = p2->next;
      s.push_back(p1);
    }

    p1 = p1->next;
    while (s.size()) {
      p2 = s.back();
      s.pop_back();
      if (p2->val != p1->val) {
        return false;
      }
      p1 = p1->next;
    }
    return true;
  }
};
