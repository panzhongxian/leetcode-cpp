class Solution {
 public:
  vector<ListNode*> splitListToParts(ListNode* head, int k) {
    vector<ListNode*> ret(k, nullptr);

    int n = 0;
    int m;
    auto cur_node = head;
    while (cur_node) {
      cur_node = cur_node->next;
      n++;
    }

    m = n / k;
    n %= k;

    cur_node = head;
    auto prev_node = new ListNode;
    prev_node->next = head;

    for (int i = 0; i < k; i++) {
      ret[i] = cur_node;
      prev_node->next = nullptr;
      for (int j = 0; j < (i < n ? m + 1 : m); j++) {
        prev_node = cur_node;
        cur_node = cur_node->next;
      }
    }
    return ret;
  }
};
