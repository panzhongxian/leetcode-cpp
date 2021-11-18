class Solution {
 public:
  int titleToNumber(string columnTitle) {
    if (columnTitle.empty()) {
      return 0;
    }
    int ret = 0;
    int factor = 1;
    int i = columnTitle.size() - 1;
    for (; i >= 0; i--) {
      ret += (columnTitle[i] - 'A' + 1) * factor;
      if (i == 0) break;
      factor *= 26;
    }
    return ret;
  }
};
