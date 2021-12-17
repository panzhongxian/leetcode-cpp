class Solution {
 public:
  vector<int> shuffle(vector<int> &nums, int n) {
    vector<int> ret(nums.size(), 0);
    int k = 0;
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < nums.size(); i += n) {
        ret[k++] = nums[i + j];
      }
    }
    return ret;
  }
};
