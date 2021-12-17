// TO ENHANCE
class Solution {
public:
  vector<int> findMode(TreeNode *root) {
    unordered_map<int, int> m;
    stack<TreeNode *> s;
    s.push(root);
    int max_occur = INT_MIN;
    while (!s.empty()) {
      auto node = s.top();
      s.pop();
      m[node->val]++;
      max_occur = max(m[node->val], max_occur);
      if (node->left) {
        s.push(node->left);
      }
      if (node->right) {
        s.push(node->right);
      }
    }
    vector<int> ret;
    for (auto &[k, v] : m) {
      if (v == max_occur) {
        ret.push_back(k);
      }
    }
    return ret;
  }
};
