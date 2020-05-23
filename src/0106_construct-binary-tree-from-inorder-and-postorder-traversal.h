#include "base.h"

typedef base::TreeNode<int> TreeNode;

class Solution {
  vector<int>* inorder;
  vector<int>* postorder;

 public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    this->inorder = &inorder;
    this->postorder = &postorder;
    return buildTreeWithIterator(0, 0, inorder.size());
  }

  TreeNode* buildTreeWithIterator(size_t in_begin, size_t post_begin,
                                  size_t len) {
    if (len == 0) {
      return nullptr;
    }
    int root_val = (*postorder)[post_begin + len - 1];
    cout << "node_val[" << root_val << "], len[" << len << "]" << endl;

    TreeNode* ret = new TreeNode(root_val);
    if (len == 1) {
      return ret;
    }

    int left_len = 0;
    while ((*inorder)[in_begin + (left_len++)] != root_val) {
    }
    left_len = left_len - 1;

    ret->left = buildTreeWithIterator(in_begin, post_begin, left_len);
    ret->right = buildTreeWithIterator(
        in_begin + left_len + 1, post_begin + left_len, len - left_len - 1);
    return ret;
  }
};
