class Solution {
public:
  string generateTheString(int n) {
    string ret(n, 'a');
    if (n % 2 == 0) {
      ret[0] = 'b';
    }
    return ret;
  }
};
