#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int Dfs(unordered_map<int, vector<int>>& s, vector<int>& informTime,
          int start) {
    auto it = s.find(start);
    if (it == s.end()) {
      return informTime[start];
    }

    int t = 0;
    for (int i : it->second) {
      t = max(t, Dfs(s, informTime, i));
    }
    return informTime[start] + t;
  }

  int numOfMinutes(int n, int headID, vector<int>& manager,
                   vector<int>& informTime) {
    unordered_map<int, vector<int>> subordination;
    for (int i = 0; i < n; i++) {
      int m = manager[i];
      if (m != -1) {
        subordination[m].push_back(i);
      }
    }

    return Dfs(subordination, informTime, headID);
  }
};
