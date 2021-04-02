class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int ret = 1;
    vector<int> l(nums.size(), 1);

    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[j] >= nums[i]) {
          continue;
        }
        int tmp_l = l[j] + 1;
        if (l[i] < tmp_l) {
          l[i] = tmp_l;
        }
        if (tmp_l > ret) {
          ret = tmp_l;
        }
      }
    }
    return ret;
  }
};
