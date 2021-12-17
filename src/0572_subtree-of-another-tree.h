class Solution {
 public:
  bool is_equal_tree(TreeNode *t1, TreeNode *t2) {
    if (t1 == nullptr) {
      return t2 == nullptr;
    }
    if (t2 == nullptr) {
      return t1 == nullptr;
    }

    return t1->val == t2->val && is_equal_tree(t1->left, t2->left) &&
           is_equal_tree(t1->right, t2->right);
  }
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    if (root == nullptr) {
      return false;
    }
    return is_equal_tree(root, subRoot) || isSubtree(root->left, subRoot) ||
           isSubtree(root->right, subRoot);
  }
};
