class Solution {
 public:
  int findNthDigit(int n) {
    int k = 1;
    int i = 1;
    int base = 1;
    for (; i < 30; i++) {
      bool flag = false;
      for (int j = 0; j < 9; j++) {
        if (n <= k * i) {
          flag = true;
          break;
        }
        n -= k * i;
        base += k;
      }
      if (flag) {
        break;
      }
      k *= 10;
    }
    int num = base + (n - 1) / i;
    string num_str = to_string(num);
    return num_str[(n - 1) % i] - '0';
  }
};
