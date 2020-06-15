#include "base.h"

class MedianFinder {
 private:
  multiset<int> left, right;

 public:
  /** initialize your data structure here. */
  MedianFinder() {}

  void addNum(int num) {
    if (right.empty()) {
      right.insert(num);
    } else if (num > *(right.begin())) {
      right.insert(num);
      if (left.size() + 1 < right.size()) {
        left.insert(*(right.begin()));
        right.erase(right.begin());
      }
    } else {
      left.insert(num);
      if (left.size() > right.size()) {
        right.insert(*(left.rbegin()));
        left.erase(std::prev(left.end()));
      }
    }
  }

  double findMedian() {
    if (left.size() == right.size()) {
      return 0.5 * (*(left.rbegin()) + *(right.begin()));
    } else {
      return *(right.begin());
    }
  }
};
