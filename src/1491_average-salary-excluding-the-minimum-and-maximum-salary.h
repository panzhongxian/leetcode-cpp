class Solution {
 public:
  double average(vector<int>& salary) {
    int min_val = INT_MAX;
    int max_val = INT_MIN;
    double sum = 0.0;
    for (int n : salary) {
      sum += n;
      if (n < min_val) {
        min_val = n;
      }
      if (n > max_val) {
        max_val = n;
      }
    }
    return (sum - min_val - max_val) / (salary.size() - 2.0);
  }
};
