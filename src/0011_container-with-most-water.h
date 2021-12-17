#include "base.h"
class Solution {
 public:
  /*
   * https://leetcode.com/problems/container-with-most-water/discuss/6099/yet-another-way-to-see-what-happens-in-the-on-algorithm
   * https://zhuanlan.zhihu.com/p/33737430
   */

  int calcCapacity(const vector<int>& height, int i, int j) {
    assert(j >= i);
    return (j - i) * min(height[i], height[j]);
  }

  int maxArea(const vector<int>& height) {
    int i, j;
    i = 0;
    j = height.size() - 1;
    int ret = 0;

    while (i < j) {
      ret = max(calcCapacity(height, i, j), ret);
      if (height[i] < height[j]) {
        i++;
      } else {
        j--;
      }
    }
    return ret;
  }
};
