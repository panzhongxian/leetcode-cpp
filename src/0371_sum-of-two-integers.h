class Solution {
 public:
  int getSum(int a, int b) {
    int next_digit = 0;
    int ret = 0;
    int digit_count = -1;
    int current_digit;
    while (a || b) {
      digit_count++;
      if (next_digit == 0) {
        if (a & b & 1) {
          next_digit = 1;
          current_digit = 0;
        } else if ((a & 1) || (b & 1)) {
          next_digit = 0;
          current_digit = 1;
        } else {  // a = 0 & b = 0
          next_digit = 0;
          current_digit = 0;
        }
      } else {  // next_digit = 1
        if (a & b & 1) {
          next_digit = 1;
          current_digit = 1;
        } else if ((a & 1) || (b & 1)) {
          next_digit = 1;
          current_digit = 0;
        } else {  // a = 0 & b = 0
          next_digit = 0;
          current_digit = 1;
        }
      }
      ret |= (current_digit << digit_count);
      a >>= 1;
      b >>= 1;
    }
    digit_count++;
    ret |= (next_digit << digit_count);
    return ret;
  }
};
