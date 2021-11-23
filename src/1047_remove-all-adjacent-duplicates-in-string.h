class Solution {
public:
  string removeDuplicates(string s) {
    string ret;

    for (char c : s) {
      if (ret.empty() || ret.back() != c) {
        ret.push_back(c);
      } else {
        ret.erase(ret.size() - 1);
      }
    }
    return ret;
  }
};
