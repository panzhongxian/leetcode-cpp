class Solution {
 public:
  int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int ret = 0;
    for (int i = 0; i < nums.size(); i += 2) {
      ret += nums[i];
    }
    return ret;
  }
};
