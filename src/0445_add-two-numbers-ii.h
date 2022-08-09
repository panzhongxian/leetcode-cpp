class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> s1, s2;
    auto insert_into_stack = [](ListNode* l, stack<int>& s) {
      while (l) {
        s.push(l->val);
        l = l->next;
      }
    };
    insert_into_stack(l1, s1);
    insert_into_stack(l2, s2);
    auto get_head_and_pop = [](stack<int>& s) -> int {
      if (s.empty()) {
        return 0;
      }
      int ret = s.top();
      s.pop();
      return ret;
    };
    int next_digit = 0;
    int current_digit;
    ListNode* ret = nullptr;
    while (!s1.empty() || !s2.empty()) {
      current_digit = get_head_and_pop(s1) + get_head_and_pop(s2) + next_digit;
      next_digit = current_digit / 10;
      ret = new ListNode(current_digit % 10, ret);
    }
    if (next_digit) {
      ret = new ListNode(next_digit, ret);
    }
    return ret;
  }
};
