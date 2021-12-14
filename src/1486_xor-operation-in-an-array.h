class Solution {
public:
  int xorOperation(int n, int start) {
    int ret = 0;
    for (int i = 0; i < n; i++) {
      ret ^= start + (i << 1);
    }
    return ret;
  }
};
