class Solution {
 public:
  string removeKdigits(string num, int k) {
    string ret;
    int i = 0;
    int j = 0;
    while (i < num.size()) {
      if (j == k) {
        if (ret.empty() && num[i] == '0') {
          i++;
          continue;
        }
        ret.push_back(num[i]);
        i++;
        continue;
      }
      if (ret.empty()) {
        if (num[i] != '0') {
          ret.push_back(num[i]);
        }
        i++;
        continue;
      }
      if (num[i] < ret.back()) {
        ret.pop_back();
        j++;
      } else {
        ret.push_back(num[i++]);
      }
    }
    while (j < k && !ret.empty()) {
      ret.pop_back();
      j++;
    }
    return ret.empty() ? "0" : ret;
  }
};
