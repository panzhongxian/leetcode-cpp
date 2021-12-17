class Solution {
 public:
  int minOperations(vector<int>& nums) {
    if (nums.empty()) return 0;
    int ret = 0;
    int prev = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] <= prev) {
        prev = prev + 1;
        ret += prev - nums[i];
      } else {
        prev = nums[i];
      }
    }
    return ret;
  }
};
