class Solution {
 public:
  int findLHS(vector<int>& nums) {
    unordered_map<int, int> m;
    for (auto num : nums) {
      if (m.find(num) == m.end()) {
        m[num] = 1;
      } else {
        m[num]++;
      }
    }
    int ret = 0;
    for (auto kv : m) {
      if (m.find(kv.first - 1) == m.end()) {
        continue;
      }
      int hs_len = kv.second + m[kv.first - 1];
      if (hs_len > ret) {
        ret = hs_len;
      }
    }
    return ret;
  }
};
