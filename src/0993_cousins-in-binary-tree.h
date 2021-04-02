class Solution {
 public:
  bool isCousins(TreeNode* root, int x, int y) {
    vector<TreeNode*> layer_nodes;
    vector<int> layer_vals;
    if (!root) return false;

    layer_nodes.push_back(root);
    layer_vals.push_back(root->val);
    while (!layer_nodes.empty()) {
      vector<TreeNode*> next_layer_nodes;
      layer_vals.clear();
      for (auto t : layer_nodes) {
        layer_vals.push_back(t ? t->val : 0);
        if (t) {
          next_layer_nodes.push_back(t->left);
          next_layer_nodes.push_back(t->right);
        }
      }

      auto it1 = find(layer_vals.begin(), layer_vals.end(), x);
      auto it2 = find(layer_vals.begin(), layer_vals.end(), y);
      if (it1 == it2 && it1 == layer_vals.end()) {
        layer_nodes = move(next_layer_nodes);
        continue;
      }

      if (it1 != layer_vals.end() && it2 != layer_vals.end()) {
        int index1 = std::distance(layer_vals.begin(), it1);
        int index2 = std::distance(layer_vals.begin(), it2);
        return (index1 >> 1) != (index2 >> 1);
      }

      // 在一层中找到其中一个 -> 深度不同
      return false;
    }

    return false;
  }
};
