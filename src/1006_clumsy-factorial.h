class Solution {
 public:
  int clumsy(int n) {
    int ret = 0;
    int t = 0;
    for (int i = 0; i < n; i++) {
      int k = n - i;
      switch (i % 4) {
        case 0:
          t = (i == 0) ? k : -k;
          break;
        case 1:
          t *= k;
          break;
        case 2:
          t /= k;
          ret += t;
          t = 0;
          break;
        case 3:
          ret += k;
      }
    }
    ret += t;
    return ret;
  }
};
