class Solution {
 public:
  int findBottomLeftValue(TreeNode* root) {
    vector<TreeNode*> v1{root};
    vector<TreeNode*> v2;
    int ret;
    while (!v1.empty()) {
      ret = v1[0]->val;
      v2.clear();
      for (auto& x : v1) {
        if (x->left) {
          v2.push_back(x->left);
        }
        if (x->right) {
          v2.push_back(x->right);
        }
      }
      v1 = move(v2);
    }
    return ret;
  }
};
