class Solution {
 public:
  bool findTarget(TreeNode *root, int k) {
    unordered_set<int> s;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      if (q.front()->left) {
        q.push(q.front()->left);
      }
      if (q.front()->right) {
        q.push(q.front()->right);
      }
      s.insert(q.front()->val);
      q.pop();
    }
    for (const auto &i : s) {
      if (s.find(k - i) != s.end() && (i * 2) != k) {
        return true;
      }
    }
    return false;
  }
};
