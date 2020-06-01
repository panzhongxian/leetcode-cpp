#include "base.h"
class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    if (triangle.size() == 0) {
      return 0;
    }
    if (triangle.size() == 1) {
      return triangle[0][0];
    }

    vector<int> pre_weight(triangle.size(), 0);
    vector<int> cur_weight(triangle.size(), 0);
    pre_weight[0] = triangle[0][0];
    for (size_t i = 1; i < triangle.size(); ++i) {
      for (size_t j = 0; j < triangle[i].size(); ++j) {
        if (j == 0) {
          cur_weight[j] = pre_weight[j] + triangle[i][j];
        } else if (j == triangle[i].size() - 1) {
          cur_weight[j] = pre_weight[j - 1] + triangle[i][j];
        } else {
          cur_weight[j] =
              min(pre_weight[j - 1], pre_weight[j]) + triangle[i][j];
        }
      }
      swap(pre_weight, cur_weight);
    }
    int ret = pre_weight[0];
    for (size_t i = 1; i < pre_weight.size(); ++i) {
      if (pre_weight[i] < ret) {
        ret = pre_weight[i];
      }
    }
    return ret;
  }
};
