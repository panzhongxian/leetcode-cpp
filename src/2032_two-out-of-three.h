#include "base.h"

class T {
 public:
  int64_t left;
  int64_t right;

  T() : left(0), right(0) {}
  void insert(int i) {
    if (i > 50) {
      i -= 50;
      left |= (1LL << i);
    } else {
      right |= (1LL << i);
    }
  }
  vector<int> dump() {
    vector<int> ret;
    for (int i = 1; i <= 50; i++) {
      if (right & (1LL << i)) {
        ret.push_back(i);
      }
      if (left & (1LL << i)) {
        ret.push_back(i + 50);
      }
    }
    return ret;
  }
};

T operator&(const T& t1, const T& t2) {
  T t;
  t.left = t1.left & t2.left;
  t.right = t1.right & t2.right;
  return t;
}
T operator|(const T& t1, const T& t2) {
  T t;
  t.left = t1.left | t2.left;
  t.right = t1.right | t2.right;
  return t;
}

class Solution {
 public:
  vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2,
                            vector<int>& nums3) {
    T t1, t2, t3, t;
    for (auto num : nums1) {
      t1.insert(num);
    }
    for (auto num : nums2) {
      t2.insert(num);
    }
    for (auto num : nums3) {
      t3.insert(num);
    }
    t = (t1 & t2) | (t1 & t3) | (t2 & t3);
    return t.dump();
  }
};
