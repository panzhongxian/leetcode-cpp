class Solution {
 public:
  string removeOuterParentheses(string s) {
    int value = 0;
    string ret;
    for (char c : s) {
      bool omit_flag = false;
      omit_flag |= value == 0;
      if (c == '(') {
        value--;
      } else {
        value++;
      }
      omit_flag |= value == 0;
      if (!omit_flag) {
        ret.push_back(c);
      }
    }
    return ret;
  }
};
