#include <map>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool eraseLeaf(map<int, pair<unordered_set<int>, unordered_set<int>>>& m,
                 int i) {
    if (!m[i].second.empty()) return false;

    queue<vector<int>> pair_to_erase;
    for (int j : m[i].first) {
      pair_to_erase.push({j, i});
    }
    m.erase(i);
    while (!pair_to_erase.empty()) {
      auto& v = pair_to_erase.front();
      m[v[0]].second.erase(v[1]);
      if (m[v[0]].second.empty()) {
        for (int j : m[v[0]].first) {
          pair_to_erase.push({j, v[0]});
        }
        m.erase(v[0]);
      }
      pair_to_erase.pop();
    }
    return true;
  }

  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // course number -> <prev_course, next_course>
    map<int, pair<unordered_set<int>, unordered_set<int>>> m;
    for (auto it = prerequisites.begin(); it != prerequisites.end(); it++) {
      int curr = (*it)[0];
      int prev = (*it)[1];
      m[curr].first.insert(prev);
      m[prev].second.insert(curr);
    }
    while (!m.empty()) {
      bool found_flag = false;
      for (auto it = m.begin(); it != m.end(); it++) {
        if (eraseLeaf(m, it->first)) {
          found_flag = true;
          break;
        }
      }
      if (!found_flag) {
        return false;
      }
    }
    return true;
  }
};
