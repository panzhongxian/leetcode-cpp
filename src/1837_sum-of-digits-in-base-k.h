class Solution {
 public:
  int sumBase(int n, int k) {
    int ret = 0;
    while (n) {
      ret += (n % k);
      n /= k;
    }
    return ret;
  }
};
