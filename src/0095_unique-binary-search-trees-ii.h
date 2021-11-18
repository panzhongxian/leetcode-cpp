#include "base.h"

typedef base::TreeNode<int> TreeNode;

class Solution {
 public:
  // include left, exclude right
  vector<TreeNode*> generateTrees(int start, int end) {
    if (start == end) {
      return vector<TreeNode*>{nullptr};
    }

    vector<TreeNode*> ret;

    for (int i = start; i < end; i++) {
      for (TreeNode* tl : generateTrees(start, i))
        for (TreeNode* tr : generateTrees(i + 1, end)) {
          TreeNode* node = new TreeNode;
          node->val = i;
          node->left = tl;
          node->right = tr;
          ret.push_back(node);
        }
    }
    return ret;
  }
  vector<TreeNode*> generateTrees(int n) { return generateTrees(1, n + 1); }
};
