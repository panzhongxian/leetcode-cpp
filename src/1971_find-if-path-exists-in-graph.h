#include <climits>

#include "base.h"

class Solution {
 public:
  bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
    if (start > end) {
      swap(start, end);
    }
    if (start == end) {
      return true;
    }

    int prev_start = INT_MAX;
    map<int, set<int>> m;
    for (auto& v : edges) {
      m[v[0]].insert(v[1]);
      m[v[1]].insert(v[0]);
    }
    auto it = m.find(start);
    if (it == m.end()) return false;

    set<int> diff(m[start]);
    set<int> s;
    while (!diff.empty()) {
      set<int> new_diff;
      for (int i : diff) {
        s.insert(i);
        if (i == end) {
          return true;
        }
        if (it = m.find(i); it == m.end()) {
          continue;
        }
        for (int ii : it->second) {
          if (s.find(ii) != s.end() || diff.find(ii) != diff.end()) {
            continue;
          }
          new_diff.insert(ii);
        }
        m.erase(it);
      }
      diff = new_diff;
    }
    return false;
  }
};
