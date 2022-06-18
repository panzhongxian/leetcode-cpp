class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    map<int, int> m;
    m[0] = -1;
    int remaining = 0;
    for (int i = 0; i < nums.size(); i++) {
      remaining += nums[i];
      remaining %= k;
      if (m.find(remaining) == m.end()) {
        m[remaining] = i;
      } else if (i - m[remaining] > 1) {
        return true;
      }
    }
    return false;
  }
};
