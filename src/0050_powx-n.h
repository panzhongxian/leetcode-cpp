class Solution {
 public:
  double myPow(double x, int old_n) {
    long long n = old_n;
    bool negative_flag = (n < 0);
    if (negative_flag) {
      n = -n;  // 此处有越界问题 -2^31 <= n <= 2^31-1
    }

    double ret = 1.0;
    double factor = x;
    while (n > 0) {
      if (n & 1) {
        ret = ret * factor;
      }
      n >>= 1;
      factor = factor * factor;
    }

    if (negative_flag) {
      ret = 1.0 / ret;
    }
    return ret;
  };
};
