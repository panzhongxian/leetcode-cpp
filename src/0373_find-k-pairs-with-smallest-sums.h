#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                     int k) {
    auto cmp = [&nums1, &nums2](pair<int, int>& a, pair<int, int>& b) {
      return nums1[a.first] + nums2[a.second] >
             nums1[b.first] + nums2[b.second];
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(
        cmp);
    pq.push({0, 0});
    vector<vector<int>> ret;
    while (ret.size() < k && !pq.empty()) {
      auto [i, j] = pq.top();
      pq.pop();
      ret.push_back({nums1[i], nums2[j]});
      if (j == 0) {
        if (i + 1 < nums1.size()) {
          pq.push({i + 1, j});
        }
      }
      if (j + 1 < nums2.size()) {
        pq.push({i, j + 1});
      }
    }
    return ret;
  }
};
