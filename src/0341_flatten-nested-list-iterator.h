#include <cassert>
#include <iostream>
#include <stack>
#include <vector>

#include "nested_integer.h"

using std::stack;
using std::vector;

class NestedIterator {
 public:
  NestedIterator(const vector<NestedInteger>& nestedList) {
    nestedListIterStack.push(nestedList.begin());
    nestedListEndIterStack.push(nestedList.end());
    KeepStackTopWithIntegerIter();
  }

  void KeepStackTopWithIntegerIter() {
    while (!nestedListIterStack.empty()) {
      if (nestedListIterStack.top() == nestedListEndIterStack.top()) {
        nestedListIterStack.pop();
        nestedListEndIterStack.pop();

        if (!nestedListIterStack.empty()) {
          // nestedListIterStack.top() can't be vector::end();
          nestedListIterStack.top()++;
        }
        continue;
      }

      if (nestedListIterStack.top()->isInteger()) {
        break;
      }
      auto& value_list = nestedListIterStack.top()->getList();
      nestedListIterStack.push(value_list.begin());
      nestedListEndIterStack.push(value_list.end());
    }
  }

  int next() {
    int ret = nestedListIterStack.top()->getInteger();
    nestedListIterStack.top()++;
    KeepStackTopWithIntegerIter();
    return ret;
  }

  bool hasNext() { return !nestedListIterStack.empty(); }

 private:
  stack<vector<NestedInteger>::const_iterator> nestedListIterStack;
  stack<vector<NestedInteger>::const_iterator> nestedListEndIterStack;
};
