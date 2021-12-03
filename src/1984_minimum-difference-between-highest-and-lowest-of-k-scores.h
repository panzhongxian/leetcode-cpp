class Solution {
public:
  int minimumDifference(vector<int> &nums, int k) {
    if (k == 1) {
      return 0;
    }
    sort(nums.begin(), nums.end());
    int ret = INT_MAX;
    int curr_diff;
    for (int i = 0; i <= nums.size() - k; i++) {
      curr_diff = nums[i + k - 1] - nums[i];
      if (curr_diff < ret) {
        ret = curr_diff;
      }
    }
    return ret;
  }
};
