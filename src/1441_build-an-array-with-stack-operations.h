#include "base.h"

class Solution {
 public:
  vector<string> buildArray(vector<int>& target, int n) {
    int k = 0;
    vector<string> ret;
    for (int i = 1; i <= n && k < target.size(); i++) {
      ret.push_back("Push");
      if (i < target[k]) {
        ret.push_back("Pop");
      } else {
        k++;
      }
    }
    return ret;
  }
};
