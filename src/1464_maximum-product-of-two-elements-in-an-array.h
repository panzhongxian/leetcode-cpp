class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int i = INT_MIN;
    int j = INT_MIN;
    for (int num : nums) {
      if (num > i) {
        j = i;
        i = num;
      } else if (num > j) {
        j = num;
      }
    }
    return (i - 1) * (j - 1);
  }
};
