#include "base.h"

typedef base::TreeNode<int> TreeNode;

class Solution {
  const vector<int>* vec_ptr;

 public:
  TreeNode* sortedArrayToBstWithIndex(size_t idx_begin, size_t len) {
    if (len <= 0) {
      return nullptr;
    }
    size_t mid = len / 2;

    // [idx_begin, idx_begin + mid)
    // idx_begin + mid
    // [idx_begin + mid + 1, idx_begin + len)

    TreeNode* ret = new TreeNode((*vec_ptr)[idx_begin + mid]);
    cout << "idx_begin: " << idx_begin << ", len: " << len
         << ", mid value: " << (*vec_ptr)[idx_begin + mid] << ", "     //
         << "left: [" << idx_begin << ", " << idx_begin + mid << ") "  //
         << "mid: " << mid                                             //
         << "right: [" << idx_begin + mid + 1 << ", " << idx_begin + mid << ")"
         << endl;

    ret->left = sortedArrayToBstWithIndex(idx_begin, mid);
    ret->right = sortedArrayToBstWithIndex(idx_begin + mid + 1, len - mid - 1);
    return ret;
  }

  TreeNode* sortedArrayToBST(const vector<int>& nums) {
    vec_ptr = &nums;
    return sortedArrayToBstWithIndex(0, nums.size());
  }
};
