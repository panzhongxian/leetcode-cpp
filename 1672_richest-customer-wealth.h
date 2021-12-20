class Solution {
 public:
  int maximumWealth(vector<vector<int>>& accounts) {
    int ret = INT_MIN;
    for (auto& v : accounts) {
      int sum = 0;
      for (int i : v) {
        sum += i;
      }
      if (sum > ret) {
        ret = sum;
      }
    }
    return ret;
  }
};
