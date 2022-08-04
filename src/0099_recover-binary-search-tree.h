#include <tuple>

#include "base.h"
typedef base::TreeNode<int> TreeNode;
using namespace std;

class Solution {
 private:
  TreeNode* last_unordinary_node;
  vector<TreeNode*> last_mmmm;

 public:
  void recoverTree(TreeNode* root) {
    if (root == nullptr) {
      return;
    }
    MinMaxOfTree(root);
    if (last_unordinary_node->val < last_mmmm[0]->val &&
        last_unordinary_node->val > last_mmmm[1]->val) {
      swap(last_mmmm[0]->val, last_mmmm[1]->val);

    } else if (last_unordinary_node->val < last_mmmm[0]->val) {
      swap(last_unordinary_node->val, last_mmmm[0]->val);
    } else {
      swap(last_unordinary_node->val, last_mmmm[1]->val);
    }
  }

  pair<TreeNode*, TreeNode*> MinMaxOfTree(TreeNode* root) {
    int ret_min = root->val;
    int ret_max = root->val;
    bool to_push = false;
    TreeNode* v1 = root;
    TreeNode* v2 = root;
    TreeNode* v3 = root;
    TreeNode* v4 = root;

    if (root->left) {
      tie(v1, v2) = MinMaxOfTree(root->left);
      if (v2->val > root->val) {
        to_push = true;
      }
    }
    if (root->right) {
      tie(v3, v4) = MinMaxOfTree(root->right);
      if (v3->val < root->val) {
        to_push = true;
      }
    }
    if (!to_push) {
      return {v1, v4};
    }
    last_unordinary_node = root;
    last_mmmm = {v2, v3};

    if (v1->val > root->val) {
      v1 = root;
    }
    if (v1->val > v3->val) {
      v1 = v3;
    }
    if (v4->val < root->val) {
      v4 = root;
    }
    if (v4->val < v2->val) {
      v4 = v2;
    }
    return {v1, v4};
  }
};
