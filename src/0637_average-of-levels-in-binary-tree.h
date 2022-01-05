#include "base.h"
typedef base::TreeNode<int> TreeNode;
class Solution {
 public:
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> ret;
    if (!root) {
      return ret;
    }
    vector<TreeNode*> l1, l2;
    l1.push_back(l1);
    while (!l1.empty()) {
      double sum = 0;

      l2.clear();
      for (auto l : l1) {
        if (l1->left) l2.push_back(l1->left);
        if (l1->right) l2.push_back(l1->right);
        sum += l1->val;
      }
      ret.push_back(sum / l1.size());
      l1 = std::move(l2);
    }
    return ret;
  }
};
