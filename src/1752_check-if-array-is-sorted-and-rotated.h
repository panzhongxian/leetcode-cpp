class Solution {
public:
  bool check(vector<int> &nums) {
    int breakpoint = -1;
    int prev = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] < prev) {
        if (breakpoint != -1) {
          return false;
        }
        breakpoint = i;
      }
      prev = nums[i];
    }
    if (breakpoint == -1)
      return true;
    return nums.back() <= nums.front();
  }
};
