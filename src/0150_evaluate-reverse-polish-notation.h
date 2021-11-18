#include <stack>
#include <string>
#include <vector>

using std::stack;
using std::string;
using std::vector;

#define pop_and_assign() \
  do {                   \
    i = num_stack.top(); \
    num_stack.pop();     \
    j = num_stack.top(); \
    num_stack.pop();     \
  } while (0)

class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    int i, j;
    stack<int> num_stack;
    for (auto s : tokens) {
      if (s.size() == 1) {
        switch (s[0]) {
          case '+':
            pop_and_assign();
            num_stack.push(i + j);
            break;
          case '-':
            pop_and_assign();
            num_stack.push(i - j);
            break;
          case '*':
            pop_and_assign();
            num_stack.push(i * j);
            break;
          case '/':
            pop_and_assign();
            num_stack.push(i / j);
            break;
          default:
            num_stack.push(s[0] - '0');
        }
      } else {
        num_stack.push(atoi(s.c_str()));
      }
    }
    return num_stack.top();
  }
};
