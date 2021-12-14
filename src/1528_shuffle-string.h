class Solution {
public:
  string restoreString(string s, vector<int> &indices) {
    string ret(s);
    int k = 0;
    for (int i : indices) {
      ret[i] = s[k++];
    }
    return ret;
  }
};
