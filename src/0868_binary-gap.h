class Solution {
public:
  int binaryGap(int n) {
    if (n == 0) {
      return 0;
    }
    while (n) {
      if (n & 1) {
        break;
      }
      n >>= 1;
    }

    int ret = 0;
    int cur_distance = 0;
    n >>= 1;

    while (n) {
      if (n & 1) {
        cur_distance++;
        if (ret < cur_distance) {
          ret = cur_distance;
        }
        cur_distance = 0;
      } else {
        cur_distance++;
      }
      n >>= 1;
    }
    return ret;
  }
};
