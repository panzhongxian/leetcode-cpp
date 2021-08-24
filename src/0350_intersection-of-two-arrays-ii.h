#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ret;
    unordered_map<int, int> m;
    for (auto n : nums1) {
      if (m.find(n) == m.end()) {
        m[n] = 0;
      }
      m[n]++;
    }

    for (auto n : nums2) {
      if (m.find(n) == m.end()) {
        continue;
      }

      ret.push_back(n);
      m[n]--;
      if (m[n] == 0) {
        m.erase(m.find(n));
      }
    }
    return ret;
  }
};
