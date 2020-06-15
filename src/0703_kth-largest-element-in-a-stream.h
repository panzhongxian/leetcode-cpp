#include "base.h"

class KthLargest {
  multiset<int> s;
  int k;

 public:
  KthLargest(int k, vector<int>& nums) {
    this->k = k;
    for (auto i : nums) {
      add(i);
    }
  }

  int add(int val) {
    if ((s.size() < k) || (*s.begin() < val)) {
      s.insert(val);
    }
    if (s.size() > k) {
      s.erase(s.begin());
    }
    return *s.begin();
  }
};
