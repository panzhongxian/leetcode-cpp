class Solution {
 public:
  bool kLengthApart(vector<int>& nums, int k) {
    if (k == 0) {
      return true;
    }
    int curr_zero_len = k;
    for (int num : nums) {
      if (num == 1) {
        if (curr_zero_len < k) {
          return false;
        }
        curr_zero_len = 0;
      } else {
        curr_zero_len++;
      }
    }
    return true;
  }
};
