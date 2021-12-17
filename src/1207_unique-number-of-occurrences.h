class Solution {
 public:
  bool uniqueOccurrences(vector<int> &arr) {
    unordered_map<int, int> m;
    for (int i : arr) {
      if (m.find(i) == m.end()) {
        m[i] = 1;
      } else {
        m[i]++;
      }
    }
    set<int> s;
    for (auto &kv : m) {
      if (s.find(kv.second) != s.end()) {
        return false;
      }
      s.insert(kv.second);
    }
    return true;
  }
};
