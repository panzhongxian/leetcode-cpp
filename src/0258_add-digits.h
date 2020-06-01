class Solution {
 public:
  int addDigits(int num) {
    while (num >= 10) {
      int new_num = 0;
      while (num > 0) {
        new_num += num % 10;
        num = num / 10;
      }
      num = new_num;
    }
    return num;
  }
};
