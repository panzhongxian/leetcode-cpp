#include "base.h"

class Solution {
 public:
  vector<int> shortestToChar(string s, char c) {
    vector<int> ret(s.size(), INT_MAX);
    size_t pos = s.find(c);
    while (pos != string::npos) {
      int distance;
      for (int i = pos; i >= 0; i--) {
        distance = pos - i;
        if (ret[i] > distance) {
          ret[i] = distance;
        } else {
          break;
        }
      }
      bool next_pos_found = false;
      for (int i = pos + 1; i < s.size(); i++) {
        if (s[i] == c) {
          next_pos_found = true;
          pos = i;
          break;
        }
        distance = i - pos;
        ret[i] = distance;
      }
      if (!next_pos_found) {
        return ret;
      }
    }
    return ret;
  }
};
