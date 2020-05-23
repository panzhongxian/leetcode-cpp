#include "base.h"

typedef base::TreeNode<int> TreeNode;

class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    if (!root) return true;
    int min_val, max_val;
    bool ret = isValidBstSubTree(root, min_val, max_val);

    cout << "BST min[" << min_val << "], max[" << max_val << "]" << endl;
    return ret;
  }

  bool isValidBstSubTree(TreeNode* root, int& min_val, int& max_val) {
    assert(root);
    min_val = max_val = root->val;
    int node_min_val, node_max_val;

    if (root->left) {
      bool ret = isValidBstSubTree(root->left, node_min_val, node_max_val);
      if (!ret || node_max_val >= root->val) {
        return false;
      }
      min_val = node_min_val;
    }

    if (root->right) {
      bool ret = isValidBstSubTree(root->right, node_min_val, node_max_val);
      if (!ret || node_min_val <= root->val) {
        return false;
      }
      max_val = node_max_val;
    }
    return true;
  }
};
