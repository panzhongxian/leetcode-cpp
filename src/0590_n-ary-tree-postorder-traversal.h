#include "base.h"

class Node {
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
public:
  vector<int> postorder(Node *root) {
    vector<int> ret;
    if (root == nullptr) {
      return ret;
    }

    stack<Node *> s;
    s.push(root);
    while (!s.empty()) {
      auto current_node = s.top();
      ret.push_back(current_node->val);
      s.pop();
      for (auto child : current_node->children) {
        s.push(child);
      }
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }
};
