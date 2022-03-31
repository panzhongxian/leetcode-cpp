class Solution {
 public:
  bool checkPossibility(vector<int>& nums) {
    if (nums.size() <= 2) {
      return true;
    }
    int down_index = -1;
    for (int i = 0; i + 1 < nums.size(); i++) {
      if (nums[i] > nums[i + 1]) {
        if (down_index >= 0) {
          return false;
        }
        down_index = i;
      }
    }
    if (down_index <= 0 || down_index == nums.size() - 2) {
      return true;
    }
    return nums[down_index - 1] <= nums[down_index + 1] ||
           nums[down_index] <= nums[down_index + 2];
  }
};
