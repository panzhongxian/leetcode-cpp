class Solution {
 public:
  int arrangeCoins(int n) {
    int ret = 0;
    int line_len = 1;
    while (true) {
      if (n < line_len) {
        return ret;
      }
      n -= line_len;
      line_len++;
      ret++;
    }
  }
};
