class Solution {
 public:
  inline int get_digit_value(char c) { return c == '?' ? -1 : c - '0'; }
  string get_max_str(char a, char b, int max_ab) {
    return get_max_str(get_digit_value(a), get_digit_value(b), max_ab);
  }
  string get_max_str(int a, int b, int max_ab) {
    int ret;
    if (a == -1 && b == -1) {
      ret = max_ab;
    } else if (a == -1) {
      ret = (b <= max_ab % 10) ? (max_ab / 10 * 10 + b)
                               : ((max_ab / 10 - 1) * 10 + b);
    } else if (b == -1) {
      ret = (max_ab / 10 == a) ? max_ab : (a * 10 + 9);
    } else {
      ret = a * 10 + b;
    }
    return (ret < 10) ? "0" + to_string(ret) : to_string(ret);
  }
  string maximumTime(string time) {
    return get_max_str(time[0], time[1], 23) + ":" +
           get_max_str(time[3], time[4], 59);
  }
};
