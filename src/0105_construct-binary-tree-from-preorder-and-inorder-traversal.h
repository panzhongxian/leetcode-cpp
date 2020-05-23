#include "base.h"

typedef base::TreeNode<int> TreeNode;

class Solution {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildTreeWithIterator(preorder.begin(), preorder.end(),
                                 inorder.begin(), inorder.end());
  }

  TreeNode* buildTreeWithIterator(vector<int>::const_iterator pre_begin,
                                  vector<int>::const_iterator pre_end,
                                  vector<int>::const_iterator in_begin,
                                  vector<int>::const_iterator in_end) {
    if (distance(pre_begin, pre_end) == 0) {
      return nullptr;
    }

    TreeNode* ret = new TreeNode(*pre_begin);
    cout << *pre_begin << ", distance: " << distance(pre_begin, pre_end)
         << endl;
    if (distance(pre_begin, pre_end) == 1) {
      return ret;
    }

    int root_val = *pre_begin;
    auto inorder_root_iter = find(in_begin, in_end, root_val);

    ret->left = buildTreeWithIterator(
        pre_begin + 1, pre_begin + 1 + distance(in_begin, inorder_root_iter),
        in_begin, inorder_root_iter  //
    );

    ret->right = buildTreeWithIterator(
        pre_begin + distance(in_begin, inorder_root_iter) + 1, pre_end,  //
        next(inorder_root_iter), in_end                                  //
    );

    return ret;
  }
};
