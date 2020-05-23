#include "base.h"

typedef base::TreeNode<int> TreeNode;

class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    if (!root) {
      return vector<int>();
    }

    vector<int> ret;
    TreeNode* cur;
    int stack_top_idx = 0;
    vector<TreeNode*> stack;
    stack.push_back(root);

    while (stack.size()) {
      cur = stack[stack_top_idx];
      if (cur->left) {
        while (cur->left) {
          stack.push_back(cur->left);
          stack_top_idx++;

          auto left = cur->left;
          // TODO: 有没有方法可以改变原来树的内容
          cur->left = nullptr;
          cur = left;
        }
        continue;
      }

      ret.push_back(cur->val);
      stack.pop_back();
      stack_top_idx--;

      if (cur->right) {
        stack.push_back(cur->right);
        stack_top_idx++;
      }
    }
    return ret;
  }
};
