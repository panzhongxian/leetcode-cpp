class Solution {
 public:
  int minStartValue(vector<int>& nums) {
    int sum = 0;
    int min_sum = INT_MAX;
    for (int num : nums) {
      sum += num;
      if (sum < min_sum) {
        min_sum = sum;
      }
    }
    return 1 + max(-min_sum, 0);
  }
};
