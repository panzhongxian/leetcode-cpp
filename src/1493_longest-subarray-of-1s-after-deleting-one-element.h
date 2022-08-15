#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestSubarray(const vector<int>& nums) {
    vector<int> stat;
    for (int n : nums) {
      if (stat.empty()) {
        stat.push_back(n ? 1 : -1);
      } else if (n) {
        if (stat.back() > 0) {
          stat.back()++;
        } else {
          stat.push_back(1);
        }
      } else {
        if (stat.back() < 0) {
          stat.back()--;
        } else {
          stat.push_back(-1);
        }
      }
    }
    int ret = 0;
    for (int i = 0; i < stat.size(); i++) {
      if (stat[i] < -1) {
        if (i > 0) ret = max(ret, stat[i - 1]);
        if (i + 1 < stat.size()) ret = max(ret, stat[i + 1]);
      } else if (stat[i] == -1) {
        int len = (i == 0 ? 0 : stat[i - 1]) +
                  (i + 1 == stat.size() ? 0 : stat[i + 1]);
        ret = max(ret, len);
      } else {
        ret = max(ret, stat[i] - 1);
      }
    }
    return ret;
  }
};
