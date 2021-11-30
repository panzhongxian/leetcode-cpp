class Solution {
public:
  int minOperations(string s) {
    int a = 0; // 10101
    int b = 0; // 01010
    bool flag = true;
    for (int i = 0; i < s.size(); i++) {
      if ((flag && s[i] == '0') || (!flag && s[i] == '1')) {
        a++;
      }
      if ((flag && s[i] == '1') || (!flag && s[i] == '0')) {
        b++;
      }
      flag = !flag;
    }
    return min(a, b);
  }
};
