#include "base.h"

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(
        intervals.begin(), intervals.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

    vector<vector<int>> ret;
    for (auto& interval : intervals) {
      if (ret.size() == 0 || ret.back()[1] < interval[0]) {
        ret.push_back(interval);
        continue;
      }

      ret[ret.size() - 1][1] = max(interval[1], ret[ret.size() - 1][1]);
    }
    return ret;
  }
};
