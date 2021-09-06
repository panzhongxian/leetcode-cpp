#include <ctype.h>

#include <cassert>
#include <stack>
#include <string>

using std::stack;
using std::string;

class Solution {
 public:
  string decodeString(string s) {
    stack<int> num_stack;
    stack<string> str_stack;
    str_stack.push("");

    string cur_num = "";
    for (char c : s) {
      if (isalpha(c)) {
        str_stack.top().push_back(c);
      } else if (isdigit(c)) {
        cur_num.push_back(c);
      } else if (c == '[') {
        str_stack.push("");
        num_stack.push(atoi(cur_num.c_str()));
        cur_num = "";
      } else if (c == ']') {
        string new_str = "";
        for (int i = 0; i < num_stack.top(); i++) {
          new_str += str_stack.top();
        }
        str_stack.pop();
        str_stack.top() += new_str;
        num_stack.pop();
      } else {
        assert(false);
      }
    }
    return str_stack.top();
  }
};
