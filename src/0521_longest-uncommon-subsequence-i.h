class Solution {
public:
  int findLUSlength(string a, string b) {
    if (a.size() != b.size()) {
      return max(a.size(), b.size());
    }
    if (a == b) {
      return -1;
    }
    return a.size();
  }
};
