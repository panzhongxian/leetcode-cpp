#include <algorithm>
#include <stack>
#include <string>

using std::reverse;
using std::stack;
using std::string;

class Solution {
 public:
  string removeDuplicateLetters(string s) {
    string ret;
    int char_rest[26];
    bool char_in_stack[26];
    stack<char> ret_str_stack;
    for (int i = 0; i < 26; i++) {
      char_rest[i] = 0;
      char_in_stack[i] = false;
    }

    for (int i = 0; i < s.size(); i++) {
      char_rest[s[i] - 'a']++;
    }
    for (char c : s) {
      if (char_in_stack[c - 'a']) {
        char_rest[c - 'a']--;
        continue;
      }
      while (!ret_str_stack.empty() && ret_str_stack.top() > c &&
             char_rest[ret_str_stack.top() - 'a'] > 0) {
        char_in_stack[ret_str_stack.top() - 'a'] = false;
        ret_str_stack.pop();
      }

      ret_str_stack.push(c);
      char_in_stack[c - 'a'] = true;
      char_rest[c - 'a']--;
    }

    while (!ret_str_stack.empty()) {
      ret.push_back(ret_str_stack.top());
      ret_str_stack.pop();
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }
};
