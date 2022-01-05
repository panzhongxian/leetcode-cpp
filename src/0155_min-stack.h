#include "base.h"

class MinStack {
 public:
  /** initialize your data structure here. */
  vector<int> stack_;
  vector<int> min_stack_;
  MinStack() {}

  void push(int x) {
    if (stack_.size() == 0) {
      stack_.push_back(x);
      min_stack_.push_back(x);
    } else {
      stack_.push_back(x);
      min_stack_.push_back(min(x, min_stack_.back()));
    }
  }

  void pop() {
    if (stack_.size() > 0) {
      stack_.pop_back();
      min_stack_.pop_back();
    }
  }

  int top() {
    if (stack_.size()) {
      return stack_.back();
    }
    return 0;
  }

  int getMin() {
    if (min_stack_.size()) {
      return min_stack_.back();
    }
    return 0;
  }
};
