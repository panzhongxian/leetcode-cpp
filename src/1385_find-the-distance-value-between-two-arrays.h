class Solution {
 public:
  int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    set<int> s;
    for (int i : arr2) {
      s.insert(i);
    }
    int ret = 0;
    for (int i : arr1) {
      auto t = s.insert(i);
      if (!t.second) continue;
      if (next(t.first) != s.end() && abs(*next(t.first) - i) <= d) {
        s.erase(t.first);
        continue;
      }
      if (t.first != s.begin() && abs(*prev(t.first) - i) <= d) {
        s.erase(t.first);
        continue;
      }
      s.erase(t.first);
      ret++;
    }
    return ret;
  }
};
