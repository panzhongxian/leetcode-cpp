class Solution {
 public:
  int maxAscendingSum(vector<int>& nums) {
    int cur_sum = nums[0];
    int max_sum = nums[0];
    for (size_t i = 1; i < nums.size(); i++) {
      if (nums[i] > nums[i - 1]) {
        cur_sum += nums[i];
      } else {
        cur_sum = nums[i];
      }
      if (cur_sum > max_sum) {
        max_sum = cur_sum;
      }
    }
    return max_sum;
  }
};
