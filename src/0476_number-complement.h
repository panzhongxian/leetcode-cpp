class Solution {
 public:
  int findComplement(int num) {
    int i = num >> 1;
    int mask = 1;
    while (i) {
      mask <<= 1;
      mask |= 1;
      i >>= 1;
    }
    return num ^ mask;
  }
};
