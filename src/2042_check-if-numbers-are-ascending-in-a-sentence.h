#include "base.h"

class Solution {
 public:
  bool areNumbersAscending(string s) {
    s.push_back(' ');
    int last_num = INT_MIN;
    int curr_num;
    size_t start = s.find_first_of("0123456789");
    size_t end;

    while (start != string::npos) {
      end = s.find(' ', start);
      curr_num = atoi(s.substr(start, end - start).c_str());
      start = s.find_first_of("0123456789", end);
      if (curr_num <= last_num) {
        return false;
      }
      last_num = curr_num;
    }

    return true;
  }
};
