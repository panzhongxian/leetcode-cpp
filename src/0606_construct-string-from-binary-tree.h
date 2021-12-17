class Solution {
 public:
  string tree2str(TreeNode* root) {
    if (root == nullptr) {
      return "";
    }
    string ret = to_string(root->val);
    if (root->right) {
      ret += "(" + tree2str(root->left) + ")";
      ret += "(" + tree2str(root->right) + ")";
    } else if (root->left) {
      ret += "(" + tree2str(root->left) + ")";
    }
    return ret;
  }
};
