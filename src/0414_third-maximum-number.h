#include "base.h"

class Solution {
 public:
  int thirdMax(vector<int>& nums) {
    set<int> s;
    for (int num : nums) {
      if (s.size() < 3) {
        s.insert(num);
        continue;
      }
      if (s.find(num) == s.end() && num > *(s.begin())) {
        s.erase(*(s.begin()));
        s.insert(num);
      }
    }
    if (s.size() < 3) {
      return *s.rbegin();
    }
    return *s.begin();
  }
};
