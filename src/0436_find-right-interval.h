#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findRightInterval(const vector<vector<int>>& intervals) {
    vector<vector<int>> start_position(intervals);
    for (int i = 0; i < start_position.size(); i++) {
      start_position[i][1] = i;
    }

    auto comp = [](const vector<int>& a, const vector<int>& b) {
      return a[0] < b[0];
    };
    sort(start_position.begin(), start_position.end(), comp);

    vector<int> ret(intervals.size());
    auto comp1 = [](const vector<int>& a, const vector<int>& b) {
      return a[0] > b[0];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(comp1)> q(comp1);

    int start, position;

    for (auto& v : start_position) {
      start = v[0];
      position = v[1];

      while (!q.empty() && q.top()[0] <= start) {
        ret[q.top()[1]] = position;
        q.pop();
      }
      if (intervals[position][1] == start) {
        ret[position] = position;
      } else {
        q.push({intervals[position][1], position});
      }
    }

    while (!q.empty()) {
      ret[q.top()[1]] = -1;
      q.pop();
    }

    return ret;
  }
};
