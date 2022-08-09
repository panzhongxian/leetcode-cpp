#include <queue>
#include <vector>
using namespace std;
class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    auto cmp = [](const vector<int>& a, const vector<int>& b) {
      return a[1] > b[1];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
    for (auto& v : intervals) {
      pq.push(move(v));
    }
    int min_end = pq.top()[0];
    int interval_cnt = 0;
    while (!pq.empty()) {
      if (min_end <= pq.top()[0]) {
        interval_cnt++;
        min_end = pq.top()[1];
      }
      pq.pop();
    }
    return intervals.size() - interval_cnt;
  }
};
