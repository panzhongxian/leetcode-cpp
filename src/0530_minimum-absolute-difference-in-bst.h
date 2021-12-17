class Solution {
 public:
  vector<int> get_min_max_and_min_diff(TreeNode *root) {
    int max_val = root->val;
    int min_val = root->val;
    int min_diff = INT_MAX;
    if (root->left) {
      auto xx = get_min_max_and_min_diff(root->left);
      min_val = xx[0];
      min_diff = min(min_diff, min(xx[2], abs(root->val - xx[1])));
    }
    if (root->right) {
      auto xx = get_min_max_and_min_diff(root->right);
      max_val = xx[1];
      min_diff = min(min_diff, min(xx[2], abs(root->val - xx[0])));
    }
    return vector<int>{min_val, max_val, min_diff};
  }
  int getMinimumDifference(TreeNode *root) {
    return get_min_max_and_min_diff(root)[2];
  }
};
