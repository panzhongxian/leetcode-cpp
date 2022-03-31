class Solution {
 public:
  vector<int> largestValues(TreeNode* root) {
    vector<int> ret;
    if (root == nullptr) {
      return ret;
    }
    vector<TreeNode*> v1, v2;
    v1.push_back(root);
    while (!v1.empty()) {
      int max_val = INT_MIN;
      for (auto& t : v1) {
        if (max_val < t->val) {
          max_val = t->val;
        }
        if (t->left) {
          v2.push_back(t->left);
        }
        if (t->right) {
          v2.push_back(t->right);
        }
      }
      ret.push_back(max_val);
      v1 = move(v2);
    }
    return ret;
  }
};
