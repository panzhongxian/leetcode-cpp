#include "base.h"

typedef base::ListNode<int> ListNode;

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* head = new ListNode;
    ListNode* cur = head;

    multimap<int, ListNode*> mm;
    for (auto l : lists) {
      if (l) {
        mm.insert(pair{l->val, l});
      }
    }

    while (mm.size()) {
      auto it = mm.begin();
      cur->next = it->second;
      cur = cur->next;
      mm.erase(it);
      if (cur->next) {
        mm.insert(pair{cur->next->val, cur->next});
      }
    }

    return head->next;
  }
};
