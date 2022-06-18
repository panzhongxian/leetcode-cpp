class Solution {
 public:
  void reorderList(ListNode* head) {
    if (!head) return;
    vector<int> v;
    auto p = head;
    while (p) {
      v.push_back(p->val);
      p = p->next;
    }
    p = head;
    int i = 0;
    for (; i < (v.size() >> 1); i++) {
      p->val = v[i];
      p = p->next;
      p->val = v[v.size() - 1 - i];
      p = p->next;
    }
    if (v.size() & 1) {
      p->val = v[i];
    }
  }
};
