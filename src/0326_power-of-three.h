class Solution {
 public:
  bool isPowerOfThree(int n) {
    while (n > 0) {
      if (n % 3 != 0) {
        return n == 1;
      }
      n /= 3;
    }
    return false;
  }
};
