#include <algorithm>
#include <vector>

using std::max;
using std::min;
using std::vector;

class Solution {
 public:
  // 返回是否发生merge
  bool MergeInterval(const vector<int>& v1, vector<int>& v2) {
    if (v1[0] > v2[1] || v2[0] > v1[1]) {
      return false;
    }

    v2[0] = min(v2[0], v1[0]);
    v2[1] = max(v2[1], v1[1]);
    return true;
  }
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    vector<vector<int>> ret;
    for (const auto& interval : intervals) {
      if (MergeInterval(interval, newInterval)) {
        continue;
      }
      ret.push_back(interval);
    }

    if (ret.empty()) {
      ret.push_back(newInterval);
      return ret;
    }

    for (auto it = ret.begin(); it != ret.end(); it++) {
      if (newInterval[1] < (*it)[0]) {
        ret.insert(it, newInterval);
        return ret;
      }
    }
    ret.push_back(newInterval);
    return ret;
  }
};
