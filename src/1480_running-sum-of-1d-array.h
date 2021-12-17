class Solution {
 public:
  vector<int> runningSum(vector<int> &nums) {
    vector<int> ret(nums.size());
    int prev_sum = 0;
    int i = 0;
    for (int num : nums) {
      prev_sum += num;
      ret[i++] = prev_sum;
    }
    return ret;
  }
};
