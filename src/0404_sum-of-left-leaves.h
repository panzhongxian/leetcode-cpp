class Solution {
 public:
  int sumOfLeftLeaves(TreeNode* root) {
    if (root == NULL) {
      return 0;
    }
    if (root->left && root->left->left == NULL && root->left->right == NULL) {
      return root->left->val + sumOfLeftLeaves(root->right);
    }
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
  }
};
