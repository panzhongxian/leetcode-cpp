class Solution {
public:
  string thousandSeparator(int n) {
    string ret;
    while (n > 1000) {
      auto t = to_string(n % 1000);
      while (t.size() < 3) {
        t = "0" + t;
      }
      ret = "." + t + ret;
      n /= 1000;
    }
    ret = to_string(n) + ret;
    return ret;
  }
};
