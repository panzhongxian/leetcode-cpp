#include "base.h"
class Solution {
 public:
  bool isValid(string s) {
    vector<char> stack;
    for (char c : s) {
      switch (c) {
        case '(':
        case '[':
        case '{':
          stack.push_back(c);
          break;
        case ')':
          if (stack.empty() || stack[stack.size() - 1] != '(') return false;
          stack.pop_back();
          break;
        case ']':
          if (stack.empty() || stack[stack.size() - 1] != '[') return false;
          stack.pop_back();
          break;
        case '}':
          if (stack.empty() || stack[stack.size() - 1] != '{') return false;
          stack.pop_back();
          break;
        default:
          return false;
      }
    }
    return stack.empty();
  }
};

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.isValid(""), true);
  EXPECT_EQ(s.isValid("[]"), true);
  EXPECT_EQ(s.isValid("[(]])]"), false);
}
