#include "base.h"

typedef base::TreeNode<int> TreeNode;

class BSTIterator {
 public:
  BSTIterator(TreeNode* root) {
    vec_.clear();
    PushToVector(root);
    it_ = vec_.begin();
  }

  void PushToVector(TreeNode* root) {
    if (!root) return;
    if (root->left) PushToVector(root->left);
    vec_.push_back(root);
    if (root->right) PushToVector(root->right);
  }

  int next() {
    int val = (*it_)->val;
    it_++;
    return val;
  }

  bool hasNext() { return it_ != vec_.end(); }

 private:
  std::vector<TreeNode*> vec_;
  std::vector<TreeNode*>::iterator it_;
};
