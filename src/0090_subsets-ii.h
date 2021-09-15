#include <algorithm>
#include <map>
#include <vector>

using std::map;
using std::swap;
using std::vector;

class Solution {
 public:
  vector<vector<int>> subsetsWithDup(const vector<int>& nums) {
    vector<vector<int>> ret = {{}};
    vector<vector<int>> tmp_ret;
    map<int, int> dict;
    for (int n : nums) {
      if (dict.find(n) == dict.end()) {
        dict[n] = 0;
      }
      dict[n] += 1;
    }

    for (auto it = dict.begin(); it != dict.end(); it++) {
      vector<int> cur_repeated_ints;
      for (int i = 0; i <= it->second; i++) {
        for (auto line : ret) {
          line.insert(line.end(), cur_repeated_ints.begin(),
                      cur_repeated_ints.end());
          tmp_ret.push_back(line);
        }
        cur_repeated_ints.push_back(it->first);
      }
      ret.clear();
      swap(tmp_ret, ret);
    }
    return ret;
  }
};
