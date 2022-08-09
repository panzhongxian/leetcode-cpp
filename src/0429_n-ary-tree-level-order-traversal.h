#include <vector>

class Solution {
 public:
  vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ret;
    if (root == nullptr) return ret;
    vector<int> new_val_layer;

    vector<Node*> current_layer{root};
    vector<Node*> next_node_layer;

    while (true) {
      for (auto node : current_layer) {
        next_node_layer.insert(next_node_layer.end(), node->children.begin(),
                               node->children.end());
        new_val_layer.push_back(node->val);
      }
      if (new_val_layer.empty()) {
        break;
      }

      ret.push_back(move(new_val_layer));
      current_layer = move(next_node_layer);
    }
    return ret;
  }
};
