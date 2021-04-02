class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0;
    for (int i = 0; i < 32; ++i) {
      ret <<= 1;
      ret += n & 1;
      n >>= 1;
    }
    return ret;
  }
};
