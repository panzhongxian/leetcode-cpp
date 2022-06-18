class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    int left = 0;
    int right = nums.size();
    int middle;
    while (left <= right) {
      middle = (left + right) / 2;
      if (middle & 1) {
        if (nums[middle] == nums[middle - 1]) {
          left = middle + 1;
        } else if (nums[middle] == nums[middle + 1]) {
          right = middle;
        } else {
          return nums[middle];
        }
      } else {
        if (middle == 0) {
          return nums[middle];
        } else if (nums[middle] == nums[middle - 1]) {
          right = middle - 2;
        } else if (nums[middle] == nums[middle + 1]) {
          left = middle + 2;
        } else {
          return nums[middle];
        }
      }
    }
    return 0;
  }
};
