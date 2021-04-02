class Solution {
 public:
  int rangeSumBST(TreeNode* root, int low, int high) {
    int ret = 0;
    if (!root) {
      return ret;
    }
    if (root->val < low) {
      return rangeSumBST(root->right, low, high);
    }
    if (root->val > high) {
      return rangeSumBST(root->left, low, high);
    }
    // low <= root->val <= high
    ret += root->val;
    if (root->left) ret += rangeSumBST(root->left, low, high);
    if (root->right) ret += rangeSumBST(root->right, low, high);
    return ret;
  }
};
