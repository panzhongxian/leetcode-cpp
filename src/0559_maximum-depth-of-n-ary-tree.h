#include "base.h"

class Solution {
 public:
  int maxDepth(Node* root) {
    if (!root) {
      return 0;
    }
    vector<Node*> cur_vec{root};
    vector<Node*> next_vec;
    int depth = 1;
    while (cur_vec.size()) {
      depth++;
      for (auto n : cur_vec) {
        for (auto nn : n->children) {
          if (nn == nullptr) {
            continue;
          }
          next_vec.push_back(nn);
        }
      }
      cur_vec.clear();
      swap(next_vec, cur_vec);
    }
    return depth;
  }
};
