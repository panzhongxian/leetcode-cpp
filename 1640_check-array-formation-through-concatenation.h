class Solution {
 public:
  bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    unordered_map<int, int> m;
    for (int i = 0; i < arr.size(); i++) {
      m[arr[i]] = i;
    }

    for (auto& v : pieces) {
      int prev_index = INT_MIN;
      for (int i : v) {
        if (m.find(i) == m.end() ||
            (prev_index != INT_MIN && prev_index != m[i] - 1)) {
          return false;
        } else {
          prev_index = m[i];
        }
      }
    }
    return true;
  }
};
