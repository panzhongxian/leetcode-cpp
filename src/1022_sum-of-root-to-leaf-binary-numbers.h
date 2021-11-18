class Solution {
 public:
  typedef struct {
    int prefix;
    TreeNode* node;
  } PrefixedNode;

  int sumRootToLeaf(TreeNode* root) {
    if (!root) {
      return 0;
    }

    int ret = 0;
    stack<PrefixedNode> pn_queue;
    PrefixedNode pn;
    pn_queue.push(PrefixedNode{0, root});
    while (!pn_queue.empty()) {
      pn = pn_queue.top();
      int new_prefix = (pn.prefix << 1) + pn.node->val;
      if (pn.node->left == NULL && pn.node->right == NULL) {
        ret += new_prefix;
        pn_queue.pop();
        continue;
      }
      pn_queue.pop();
      if (pn.node->left) {
        pn_queue.push(PrefixedNode{new_prefix, pn.node->left});
      }
      if (pn.node->right) {
        pn_queue.push(PrefixedNode{new_prefix, pn.node->right});
      }
    }
    return ret;
  }
};
