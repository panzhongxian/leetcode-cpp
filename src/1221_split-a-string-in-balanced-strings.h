class Solution {
 public:
  int balancedStringSplit(string s) {
    int weight = 0;
    int ret = 0;
    for (char c : s) {
      weight += c == 'L' ? -1 : 1;
      if (weight == 0) {
        ret += 1;
      }
    }
    return ret;
  }
};
