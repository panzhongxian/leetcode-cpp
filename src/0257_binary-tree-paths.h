#include "base.h"

class Solution {
  vector<string> ret;

 public:
  void RecursivelyPaths(string prefix, TreeNode* root) {
    assert(root);
    if (prefix.length() > 0) {
      prefix += "->";
    }
    char c[10];
    snprintf(c, 10, "%d", root->val);
    prefix += string(c);
    if (root->left == nullptr && root->right == nullptr) {
      ret.push_back(prefix);
      return;
    }
    if (root->left) {
      RecursivelyPaths(prefix, root->left);
    }
    if (root->right) {
      RecursivelyPaths(prefix, root->right);
    }
  }

  vector<string> binaryTreePaths(TreeNode* root) {
    ret.clear();
    if (!root) {
      return ret;
    }
    RecursivelyPaths("", root);
    return ret;
  }
};
