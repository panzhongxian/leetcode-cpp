class Solution {
 public:
  int numberOfMatches(int n) {
    int ret = 0;
    while (n != 1) {
      ret += (n >> 1);
      if (n & 1) {
        n = (n >> 1) + 1;
      } else {
        n >>= 1;
      }
    }
    return ret;
  }
};
