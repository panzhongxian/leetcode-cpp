class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      int curr = nums[i];
      while (curr != i + 1) {
        if (nums[curr - 1] == curr) {
          return curr;
        }
        swap(nums[curr - 1], nums[i]);
        curr = nums[i];
      }
    }
    return 0;
  }
};
