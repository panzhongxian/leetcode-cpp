class Solution {
 public:
  vector<int> minSubsequence(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int total_sum = 0;
    for (auto num : nums) {
      total_sum += num;
    }

    int right_sum = 0;
    vector<int> ret;
    for (int i = nums.size() - 1; i >= 0; i--) {
      ret.push_back(nums[i]);
      right_sum += nums[i];
      total_sum -= nums[i];
      if (right_sum > total_sum) {
        return ret;
      }
    }
    return ret;
  }
};
