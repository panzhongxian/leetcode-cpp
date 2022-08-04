#include <unordered_map>

#include "base.h"

class Solution {
 public:
  int numJewelsInStones(string jewels, string stones) {
    unordered_map<char, bool> m;
    int ret = 0;
    for (char c : jewels) {
      m[c] = true;
    }
    for (char c : stones) {
      if (m.find(c) != m.end()) {
        ret++;
      }
    }
    return ret;
  }
};
