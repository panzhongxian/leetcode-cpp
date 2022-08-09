class Solution {
 public:
  int findClosestNumber(vector<int>& nums) {
    int ret = nums[0] > 0 ? nums[0] : -nums[0];

    bool negative = nums[0] < 0;

    for (int i : nums) {
      if (i == 0) {
        return 0;
      } else if (i < 0 && -i < ret) {
        ret = -i;
        negative = true;
      } else if (i > 0 && i <= ret) {  // i > 0
        ret = i;
        negative = false;
      }
    }
    return negative ? -ret : ret;
  }
};
