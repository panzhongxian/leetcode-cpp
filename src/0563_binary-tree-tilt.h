class Solution {
 public:
  pair<int, int> xx(TreeNode *root) {
    int sum = 0;
    int tilt = 0;
    if (root == nullptr) {
      return make_pair(sum, tilt);
    }
    int sum_left = 0;
    int sum_right = 0;
    if (root->left) {
      auto sum_tilt = xx(root->left);
      sum_left = sum_tilt.first;
      tilt += sum_tilt.second;
    }
    if (root->right) {
      auto sum_tilt = xx(root->right);
      sum_right = sum_tilt.first;
      tilt += sum_tilt.second;
    }
    tilt += abs(sum_left - sum_right);
    sum = sum_left + sum_right + root->val;
    return pair<int, int>(sum, tilt);
  }
  int findTilt(TreeNode *root) { return xx(root).second; }
};
