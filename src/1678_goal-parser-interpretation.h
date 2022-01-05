#include "base.h"

class Solution {
 public:
  /* G -> G
   * () -> o
   * (al) -> al
   */
  string interpret(string command) {
    string ret;
    bool left_brace = false;
    for (int i = 0; i < command.size(); i++) {
      char c = command[i];
      if (c == '(') {
        left_brace = true;
      } else if (left_brace) {
        left_brace = false;
        if (c == ')') {
          ret.push_back('o');
        } else {  // al)
          i += 2;
          ret.push_back('a');
          ret.push_back('l');
        }
      } else {
        ret.push_back('G');
      }
    }
    return ret;
  }
};
