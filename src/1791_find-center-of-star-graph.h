class Solution {
public:
  int findCenter(vector<vector<int>> &edges) {
    unordered_map<int, int> m;

    // int stop_index= edges.size();
    int stop_index = 2;
    for (int i = 0; i < stop_index; i++) {
      auto &edge = edges[i];
      m[edge[0]]++;
      m[edge[1]]++;
    }
    for (auto &kv : m) {
      if (kv.second == m.size() - 1) {
        return kv.first;
      }
    }
    return 0;
  }
};
