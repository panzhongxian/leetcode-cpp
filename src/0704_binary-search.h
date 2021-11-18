class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();
    int mid = (left + right) / 2;
    while (mid < right) {
      if (nums[mid] == target) {
        return mid;
      }
      if (nums[mid] > target) {
        right = mid;
      } else {
        left = mid + 1;
      }
      mid = (left + right) / 2;
    }
    return -1;
  }
};
