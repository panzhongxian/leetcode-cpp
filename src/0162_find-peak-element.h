class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    int left = 0;
    int right = nums.size();
    int mid, mid_val;

    assert(right > left);
    while (left < right) {
      if (left + 1 == right) {
        return left;
      }

      if (left + 2 == right) {
        return nums[left] > nums[right - 1] ? left : (right - 1);
      }

      // remaining: more than 2 elements.
      mid = (left + right) / 2;
      if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
        return mid;
      }

      if (nums[mid] < nums[mid - 1]) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};
