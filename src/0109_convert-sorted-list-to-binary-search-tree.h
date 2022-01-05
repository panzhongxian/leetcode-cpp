#include "base.h"
typedef base::ListNode<int> ListNode;
typedef base::TreeNode<int> TreeNode;

class Solution {
  vector<ListNode*> vec;

 public:
  TreeNode* FormBst(int start, int stop) {
    int mid = (start + stop) / 2;
    TreeNode* ret = new TreeNode(vec[mid]->val);
    ret->left = (mid > start) ? FormBst(start, mid - 1) : nullptr;
    ret->right = (mid < stop) ? FormBst(mid + 1, stop) : nullptr;
    return ret;
  }

  TreeNode* sortedListToBST(ListNode* head) {
    if (!head) {
      return nullptr;
    }

    while (head) {
      vec.push_back(head);
      head = head->next;
    }
    return FormBst(0, vec.size() - 1);
  }
};
