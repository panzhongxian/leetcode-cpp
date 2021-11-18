#include <algorithm>
#include <unordered_map>
#include <vector>
using std::sort;
using std::unordered_map;
using std::vector;
class Solution {
 public:
  int minSetSize(vector<int>& arr) {
    unordered_map<int, int> m;
    for (int i : arr) {
      if (m.find(i) == m.end()) {
        m[i] = 1;
      } else {
        m[i]++;
      }
    }

    vector<int> v;
    for (auto& kv : m) {
      v.push_back(kv.second);
    }
    sort(v.begin(), v.end());
    int ret = 0;
    int removed_len = 0;

    while (!v.empty()) {
      if (removed_len >= arr.size() / 2) {
        return ret;
      }
      removed_len += v.back();
      v.pop_back();
      ret++;
    }
    return ret;
  }
};
