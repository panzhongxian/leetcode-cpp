#include "base.h"

class Solution {
 public:
  vector<int> preorder(Node* root) {
    vector<int> ret;
    list<Node*> l(1, root);

    while (!l.empty()) {
      auto cur_node = *l.begin();
      ret.push_back(cur_node->val);
      l.pop_front();
      for (auto it = cur_node->children.rbegin();
           it != cur_node->children.rend(); it++) {
        l.push_front(*it);
      }
    }
    return ret;
  }
};
