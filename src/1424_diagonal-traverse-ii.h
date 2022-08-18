#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> findDiagonalOrder(const vector<vector<int>>& nums) {
    if (nums.empty()) {
      return {};
    }
    if (nums.size() == 1) {
      return nums[0];
    }
    vector<int> ret;

    queue<pair<int, int>> q1, q2;
    for (int i = 0; i < nums.size(); i++) {
      if (!nums[i].empty()) {
        q1.push({i, 0});
        ret.push_back(nums[i][0]);
      }
      while (!q2.empty()) {
        auto [m, n] = q2.front();
        q2.pop();
        if (n + 1 < nums[m].size()) {
          ret.push_back(nums[m][n + 1]);
          q1.push({m, n + 1});
        }
      }
      swap(q1, q2);
    }
    while (!q2.empty()) {
      auto [m, n] = q2.front();
      q2.pop();
      if (n + 1 < nums[m].size()) {
        ret.push_back(nums[m][n + 1]);
        q2.push({m, n + 1});
      }
    }

    return ret;
  }
};
