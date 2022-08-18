#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  int Dfs(unordered_map<int, vector<int>>& aj_list, vector<bool>& visited,
          int start) {
    if (visited[start]) {
      return 0;
    }
    visited[start] = true;

    int ret = 0;
    for (int n : aj_list[start]) {
      if (n < 0 && !visited[abs(n)]) {
        ret++;
      }
      ret += Dfs(aj_list, visited, abs(n));
    }
    return ret;
  }

  int minReorder(int n, const vector<vector<int>>& connections) {
    unordered_map<int, vector<int>> aj_list;

    for (auto& v : connections) {
      aj_list[v[1]].push_back(v[0]);
      aj_list[v[0]].push_back(-v[1]);
    }
    vector<bool> visited(n, false);
    return Dfs(aj_list, visited, 0);
  }
};
