class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> mv;
    vector<int> prev_count(numCourses, 0);
    for (auto& v : prerequisites) {
      mv[v[1]].push_back(v[0]);
      prev_count[v[0]]++;
    }
    vector<int> ret;
    bool found_zero_flag = true;
    while (ret.size() < numCourses && found_zero_flag) {
      found_zero_flag = false;

      // 去掉所有的0
      vector<int> zero_num;
      for (int i = 0; i < numCourses; i++) {
        if (prev_count[i] == 0) {
          zero_num.push_back(i);
          prev_count[i] = -1;
          ret.push_back(i);
          found_zero_flag = true;
        }
      }
      for (int i : zero_num) {
        if (mv.find(i) == mv.end()) {
          continue;
        }
        for (int j : mv[i]) {
          if (prev_count[j]-- <= 0) {
            return vector<int>{};
          }
        }
      }
    }
    return ret.size() == numCourses ? ret : vector<int>{};
  }
};
