#include "base.h"
class Solution {
 public:
  int longestValidParentheses(string s) {
    int weight[1 + s.size()];
    weight[0] = 0;
    size_t i = 1;
    for (auto c : s) {
      weight[i] = weight[i - 1] + ((c == '(') ? 1 : -1);
      i++;
    }
    map<int, size_t> first_weight_from_left;
    map<int, size_t> first_weight_from_right;
    for (size_t i = 0; i <= s.size(); ++i) {
      if (first_weight_from_left.count(weight[i]) == 0) {
        first_weight_from_left[weight[i]] = i;
      }
      first_weight_from_right[weight[i]] = i;
    }
    int ret = 0;
    for (map<int, size_t>::iterator iter = first_weight_from_left.begin();
         iter != first_weight_from_left.end(); ++iter) {
      int cur_max = first_weight_from_right[iter->first] - iter->second;
      if (cur_max > ret) {
        ret = cur_max;
      }
    }
    return ret;
  }
};
