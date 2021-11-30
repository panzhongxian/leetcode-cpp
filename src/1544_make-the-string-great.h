class Solution {
public:
  string makeGood(string s) {
    constexpr int case_diff = 'A' > 'a' ? ('A' - 'a') : ('a' - 'A');
    stack<int> char_stack;

    for (int c : s) {
      if (char_stack.empty() || abs(char_stack.top() - c) != case_diff) {
        char_stack.push(c);
      } else {
        char_stack.pop();
      }
    }
    string ret;
    while (!char_stack.empty()) {
      ret.push_back(char_stack.top());
      char_stack.pop();
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }
};
