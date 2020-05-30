#include "base.h"

class Solution {
 public:
  string SimplifyString(const string &s) {
    vector<char> stack;
    for (auto c : s) {
      switch (c) {
        case '(':
        case '*':
          stack.push_back(c);
          break;
        case ')': {
          vector<char> pop_stack;
          bool push_flag = true;

          while (stack.size()) {
            if (stack.back() == '(') {
              stack.pop_back();
              push_flag = false;
              break;
            } else if (stack.back() == '*') {
              pop_stack.push_back('*');
              stack.pop_back();
            } else if (stack.back() == ')') {
              break;
            } else {
              assert(false);
            }
          }

          while (pop_stack.size()) {
            stack.push_back(pop_stack.back());
            pop_stack.pop_back();
          }

          if (push_flag) {
            stack.push_back(')');
          }
        }
      }
    }
    string ret;
    for (char c : stack) {
      ret.append(1, c);
    }
    return ret;
  }
  bool checkValidString(string s) {
    map<string, int> pre_sub_str_weight;
    map<string, int> cur_sub_str_weight;

    s = SimplifyString(s);
    int len = s.length();

    pre_sub_str_weight["()"] = 0;
    for (int i = 0; i < len; ++i) {
      char c = s[i];
      cur_sub_str_weight.clear();
      if (c == '*') {
        for (auto &it : pre_sub_str_weight) {
          if (it.second + 1 <= len - i) {
            cur_sub_str_weight[it.first] = it.second;
          }
        }
      }

      if (c == '(' || c == '*') {
        for (auto &it : pre_sub_str_weight) {
          if (it.second + 1 <= len - i) {
            cur_sub_str_weight[it.first + "("] = it.second + 1;
          }
        }
      }

      if (c == ')' || c == '*') {
        for (auto &it : pre_sub_str_weight) {
          if (it.second > 0) {
            cur_sub_str_weight[it.first + ")"] = it.second - 1;
          }
        }
      }

      pre_sub_str_weight = cur_sub_str_weight;
    }

    for (auto &it : pre_sub_str_weight) {
      if (it.second == 0) {
        return true;
      }
    }
    return false;
  }
};
