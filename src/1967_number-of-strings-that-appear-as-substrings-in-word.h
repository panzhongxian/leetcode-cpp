class Solution {
 public:
  int numOfStrings(vector<string>& patterns, string word) {
    int ret = 0;
    for (auto& s : patterns) {
      if (word.find(s) != string::npos) {
        ret++;
      }
    }
    return ret;
  }
};
