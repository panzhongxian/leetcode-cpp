class Solution {
public:
  int findMinLargerValue(TreeNode *root, int val) {
    if (root == nullptr) {
      return -1;
    }

    if (root->val > val) {
      return root->val;
    }

    if (root->val == val && root->left == nullptr) {
      return -1;
    }

    int i = findMinLargerValue(root->left, val);
    int j = findMinLargerValue(root->right, val);
    if (i == -1 && j == -1) {
      return -1;
    } else if (i == -1) {
      return j;
    } else if (j == -1) {
      return i;
    } else {
      return min(i, j);
    }
  }

  int findSecondMinimumValue(TreeNode *root) {
    return findMinLargerValue(root, root->val);
  }
};
