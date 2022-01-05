#include "base.h"

class Solution {
 public:
  int get_soldier_count(const vector<int> vec) {
    // TODO using binary search
    int ret = 0;
    for (int i : vec) {
      if (i == 0) {
        break;
      }
      ret++;
    }
    return ret;
  }
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    assert(mat.size() >= k);
    multimap<int, int> soldier_value_index;
    for (int i = 0; i < mat.size(); ++i) {
      int value = get_soldier_count(mat[i]);
      soldier_value_index.insert({value, i});
    }
    vector<int> ret;
    for (auto& p : soldier_value_index) {
      if (ret.size() == k) {
        return ret;
      }
      ret.push_back(p.second);
    }
    return ret;
  }
};
