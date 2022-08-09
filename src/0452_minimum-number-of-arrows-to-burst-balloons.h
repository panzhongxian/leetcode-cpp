#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
      return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
    });

    int ret = 0;
    vector<int> most_left_ballon;
    for (int i = 0; i < points.size();) {
      if (most_left_ballon.empty()) {
        ret += 1;
        most_left_ballon = points[i++];
        continue;
      }
      if (points[i][0] <= most_left_ballon[1]) {
        most_left_ballon[1] = min(points[i][1], most_left_ballon[1]);
        i++;
      } else {
        most_left_ballon.clear();
      }
    }
    return ret;
  }
};
