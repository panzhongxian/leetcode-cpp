class Solution {
public:
  int getLucky(string s, int k) {
    int digits[s.size() * 2];
    int digits_len = 0;
    for (char c : s) {
      int v = c - 'a' + 1;
      if (v >= 20) {
        digits[digits_len++] = 2;
        digits[digits_len++] = v - 20;
      } else if (v >= 10) {
        digits[digits_len++] = 1;
        digits[digits_len++] = v - 10;
      } else {
        digits[digits_len++] = v;
      }
    }
    for (int i = 0; i < k; i++) {
      int sum = 0;
      for (int j = 0; j < digits_len; j++) {
        sum += digits[j];
      }
      if (sum < 10) {
        return sum;
      }
      int new_digits_len = 0;
      while (sum) {
        digits[new_digits_len++] = sum % 10;
        sum /= 10;
      }
      digits_len = new_digits_len;
    }

    reverse(digits, digits + digits_len);
    int ret = 0;
    for (int i = 0; i < digits_len; i++) {
      ret = ret * 10 + digits[i];
    }
    return ret;
  }
};
