class Solution {
public:
  bool checkPerfectNumber(int num) {
    int upper_bound = num - 1;
    int sum = 0;
    for (int i = 1; i < upper_bound; i++) {
      if (num % i != 0) {
        continue;
      }
      sum += i;
      upper_bound = num / i;
      cout << i << endl;
      if (upper_bound != i && upper_bound != num) {
        sum += upper_bound;
      }
      cout << upper_bound << endl;
    }
    return sum == num;
  }
};
