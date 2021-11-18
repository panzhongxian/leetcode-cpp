/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ret;
    if (!root) return ret;
    if (root->left) {
      auto r1 = postorderTraversal(root->left);
      ret.insert(ret.end(), make_move_iterator(r1.begin()),
                 make_move_iterator(r1.end()));
    }
    if (root->right) {
      auto r2 = postorderTraversal(root->right);
      ret.insert(ret.end(), make_move_iterator(r2.begin()),
                 make_move_iterator(r2.end()));
    }
    ret.push_back(root->val);
    return ret;
  }
};
