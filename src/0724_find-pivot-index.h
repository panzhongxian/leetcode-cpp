class Solution {
public:
  int pivotIndex(vector<int> &nums) {
    vector<int> sum_left(nums.size(), 0);
    vector<int> sum_right(nums.size(), 0);

    for (int i = nums.size() - 2; i >= 0; i--) {
      sum_right[i] = sum_right[i + 1] + nums[i + 1];
    }
    for (int i = 0; i < nums.size(); i++) {
      if (i != 0) {
        sum_left[i] = sum_left[i - 1] + nums[i - 1];
      }
      if (sum_left[i] == sum_right[i]) {
        return i;
      }
    }
    return -1;
  }
};
