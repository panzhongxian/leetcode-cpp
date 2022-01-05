#include "base.h"

class Solution {
 public:
  bool checkIfExist(vector<int>& arr) {
    set<int> s;
    for (int i : arr) {
      if (s.find(i * 2) != s.end()) {
        return true;
      } else if (i % 2 == 0 && s.find(i / 2) != s.end()) {
        return true;
      } else {
        s.insert(i);
      }
    }
    return false;
  }
};
