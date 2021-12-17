class Solution {
 public:
  string reformat(string s) {
    string s1, s2;
    for (char c : s) {
      if (c >= '0' && c <= '9') {
        s1.push_back(c);
      } else {
        s2.push_back(c);
      }
    }

    if (s1.size() < s2.size()) {
      swap(s1, s2);
    }
    if (s1.size() - s2.size() > 1) {
      return "";
    }
    int i = 0;
    string ret;
    for (; i < s2.size(); i++) {
      ret.push_back(s1[i]);
      ret.push_back(s2[i]);
    }
    if (i < s1.size()) {
      ret.push_back(s1[i]);
    }
    return ret;
  }
};
