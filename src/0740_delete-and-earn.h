class Solution {
 public:
  int maxSum(const vector<int>& nums) {
    int ret = 0;
    vector<int> sums(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++) {
      if (i == 0 || i == 1) {
        sums[i] = nums[i];
      } else if (i == 2) {
        sums[i] = nums[i] + sums[i - 2];
      } else {
        sums[i] = nums[i] + max(sums[i - 2], sums[i - 3]);
      }
      if (sums[i] > ret) {
        ret = sums[i];
      }
    }
    return ret;
  }
  int deleteAndEarn(vector<int>& nums) {
    map<int, int> m;
    for (int i : nums) {
      m[i] += i;
    }
    m[m.rbegin()->first + 2] = 0;
    int prev_int = m.begin()->first - 2;
    vector<int> continuous_int_sum;
    int ret = 0;
    for (auto kv : m) {
      if (kv.first == prev_int + 1) {
        continuous_int_sum.push_back(kv.second);
        prev_int = kv.first;
        continue;
      }
      ret += maxSum(continuous_int_sum);
      continuous_int_sum = {kv.second};
      prev_int = kv.first;
    }
    return ret;
  }
};
