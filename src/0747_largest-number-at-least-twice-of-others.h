class Solution {
public:
  int dominantIndex(vector<int> &nums) {
    if (nums.size() == 1) {
      return 0;
    }
    int ret = 0;
    int first_max = nums[0];
    int second_max = nums[1];
    if (first_max < second_max) {
      swap(first_max, second_max);
      ret = 1;
    }
    for (int i = 2; i < nums.size(); i++) {
      if (nums[i] > first_max) {
        second_max = first_max;
        first_max = nums[i];
        ret = i;
      } else if (nums[i] > second_max) {
        second_max = nums[i];
      }
    }
    return first_max >= (second_max << 1) ? ret : -1;
  }
};
