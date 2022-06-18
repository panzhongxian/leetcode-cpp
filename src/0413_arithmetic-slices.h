class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    if (nums.size() < 3) {
      return 0;
    }
    vector<int> diff(nums.size(), 0);
    int i = 0;
    for (; i < nums.size() - 1; i++) {
      diff[i] = nums[i + 1] - nums[i];
    }
    diff[i] = diff[i - 1] + 1;

    int prev_diff = diff[0];
    int cont_diff_cnt = 0;
    int ret = 0;
    for (i = 0; i < diff.size(); i++) {
      if (diff[i] == prev_diff) {
        cont_diff_cnt++;
        continue;
      }
      prev_diff = diff[i];
      if (cont_diff_cnt >= 2) {
        ret += (1 + (cont_diff_cnt - 1)) * (cont_diff_cnt - 1) / 2;
      }
      cont_diff_cnt = 1;
    }
    return ret;
  }
};
