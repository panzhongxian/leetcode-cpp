class Solution {
 public:
  bool isPowerOfTwo(int n) {
    bool flag = false;
    while (n) {
      if (n & 1) {
        flag = true;
      }
      n >>= 1;
      if (flag && n) {
        return false;
      }
    }
    return flag;
  }
};
