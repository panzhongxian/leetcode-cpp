class Solution {
 public:
  string destCity(vector<vector<string>> &paths) {
    unordered_set<string> s;
    for (const auto &v : paths) {
      s.insert(v[0]);
    }
    for (const auto &v : paths) {
      if (s.find(v[1]) == s.end()) {
        return v[1];
      }
    }
    return "";
  }
};
