#include <climits>

#include "base.h"

class Solution {
 public:
  struct Counter {
    int start_index;
    int end_index;
    int cnt;
  };

  int findShortestSubArray(vector<int>& nums) {
    int max_freq = 0;
    unordered_map<int, Counter> m;

    for (int i = 0; i < nums.size(); i++) {
      int num = nums[i];
      if (m.find(num) == m.end()) {
        m[num] = Counter{i, i, 1};
      } else {
        m[num].end_index = i;
        m[num].cnt++;
      }
      if (m[num].cnt > max_freq) {
        max_freq = m[num].cnt;
      }
    }
    int ret = INT_MAX;
    for (auto& kv : m) {
      if (kv.second.cnt != max_freq) {
        continue;
      }
      int sub_array_len = kv.second.end_index - kv.second.start_index + 1;
      if (sub_array_len < ret) {
        ret = sub_array_len;
      }
    }
    return ret;
  }
};
