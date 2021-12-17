class Solution {
 public:
  int arraySign(vector<int>& nums) {
    bool minus_flag = false;

    for (int n : nums) {
      if (n < 0) {
        minus_flag = !minus_flag;
      } else if (n == 0) {
        return 0;
      }
    }
    return minus_flag ? -1 : 1;
  }
};
