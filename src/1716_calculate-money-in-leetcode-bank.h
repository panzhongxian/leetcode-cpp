class Solution {
 public:
  int totalMoney(int n) {
    int i = n / 7;
    int j = n % 7;
    int ret = 7 * i * (i + 7) / 2;
    for (int m = 1; m <= j; m++) {
      ret += i + m;
    }
    return ret;
  }
};
