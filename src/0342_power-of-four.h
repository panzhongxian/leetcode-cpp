class Solution {
 public:
  bool isPowerOfFour(int n) {
    while (n > 0) {
      if ((n & 3) != 0) {
        return n == 1;
      }
      n >>= 2;
    }
    return false;
  }
};
