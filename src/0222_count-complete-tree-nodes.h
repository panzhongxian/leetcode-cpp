class Solution {
 public:
  int countNodes(TreeNode* root) {
    if (!root) {
      return 0;
    }
    int layer_n = 0;
    TreeNode* cur = root;
    while (cur) {
      layer_n++;
      cur = cur->right;
    }
    int left, right, mid;
    // [left, right]
    left = int(pow(2, layer_n));
    right = (left << 1) - 1;

    // find first NULL node
    while (left < right) {
      mid = (left + right) / 2;
      TreeNode* tmp_node = get_node_by_number(root, mid);
      if (tmp_node) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    // left == right
    return left - 1;
  }
  TreeNode* get_node_by_number(TreeNode* root, int n) {
    if (n == 0) {
      return NULL;
    }

    vector<bool> tree_route;
    while (n) {
      tree_route.push_back(n & 1);
      n >>= 1;
    }
    TreeNode* ret;
    ret = root;
    tree_route.pop_back();
    for (auto it = tree_route.rbegin(); it != tree_route.rend(); ++it) {
      ret = (*it) ? ret->right : ret->left;
    }

    return ret;
  }
};
