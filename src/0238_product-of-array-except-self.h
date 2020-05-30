#include "base.h"

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int len = nums.size();
    assert(len > 1);

    vector<int> ret(len);
    vector<int> forward_product(len);
    vector<int> backward_product(len);

    forward_product[0] = 1;
    backward_product[len - 1] = 1;

    for (int i = 1; i < len; ++i) {
      forward_product[i] = forward_product[i - 1] * nums[i - 1];
    }

    for (int i = len - 2; i >= 0; --i) {
      backward_product[i] = backward_product[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < len; ++i) {
      ret[i] = forward_product[i] * backward_product[i];
    }

    return ret;
  }
};
