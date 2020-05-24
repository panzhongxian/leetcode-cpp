#include "base.h"

typedef base::TreeNode<int> TreeNode;

class Solution {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ret;
    if (!root) {
      return ret;
    }

    vector<TreeNode*> stack({root});
    while (stack.size()) {
      // 为什么这里使用引用不符合逻辑？如果pop_back之后该引用指向新的尾部元素？
      // auto& cur_node = stack.back();
      auto cur_node = stack.back();

      ret.push_back(cur_node->val);
      stack.pop_back();

      if (cur_node->right) {
        stack.push_back(cur_node->right);
      }
      if (cur_node->left) {
        stack.push_back(cur_node->left);
      }
    }
    return ret;
  }
};
