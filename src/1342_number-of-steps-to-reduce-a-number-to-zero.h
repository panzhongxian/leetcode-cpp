class Solution {
 public:
  int numberOfSteps(int num) {
    int ret = 0;
    while (num) {
      if (num & 1) {
        ret++;
        num ^= 1;
      } else {
        num >>= 1;
        ret++;
      }
    }
    return ret;
  }
};
