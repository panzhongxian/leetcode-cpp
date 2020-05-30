#include "base.h"

typedef base::TreeNode<int> TreeNode;
class Solution {
 private:
  vector<int> v;

 public:
  int FindSplitIndex(int root_val, int left, int right) {
    int mid;
    assert(left >= 0 && left < v.size());
    cout << left << "----" << right << endl;

    while (left < right) {
      mid = (left + right) / 2;
      if (v[mid] < root_val) {
        left = mid + 1;
        if (left == right) {
          return right;
        }
      } else {
        right = mid;
      }
    }

    int ret = v[left] > root_val ? left : left + 1;
    return ret;
  }

  TreeNode* bstFromPreorder(vector<int>& preorder) {
    if (preorder.size() == 0) {
      return nullptr;
    }
    v = preorder;
    return bstFromPreorder(0, preorder.size());
  }

  TreeNode* bstFromPreorder(int left, int right) {
    TreeNode* ret = new TreeNode(v[left]);
    if (left + 1 == right) {  // 注意左开右闭
      return ret;
    }

    cout << "LEFT+1: " << left + 1 << endl;
    cout << "RIGHT: " << right << endl;

    int right_start_idx = FindSplitIndex(ret->val, left + 1, right);

    cout << "root->val: " << ret->val << endl;

    if (right_start_idx == left + 1) {
      cout << "left empty. left: " << left << ", right: " << right << endl;
      ret->left = nullptr;
    } else {
      cout << "left: [" << (left + 1) << "," << right_start_idx << ")" << endl;
      ret->left = bstFromPreorder(left + 1, right_start_idx);
    }

    if (right_start_idx >= right) {
      cout << "right empty. left: " << left << ", right: " << right << endl;
      ret->right = nullptr;
    } else {
      cout << "right: [" << right_start_idx << "," << right << ")" << endl;
      ret->right = bstFromPreorder(right_start_idx, right);
    }
    return ret;
  }
};
