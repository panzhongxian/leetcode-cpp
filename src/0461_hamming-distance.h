class Solution {
 public:
  int hammingDistance(int x, int y) {
    int z = x ^ y;
    int ret = 0;
    while (z) {
      ret += (z & 1);
      z >>= 1;
    }
    return ret;
  }
};
