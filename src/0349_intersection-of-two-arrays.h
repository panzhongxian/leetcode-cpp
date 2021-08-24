#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ret;
    unordered_map<int, int> m;
    for (auto n : nums1) {
      m[n] = 1;
    }

    for (auto n : nums2) {
      if (m.find(n) == m.end()) {
        continue;
      }

      ret.push_back(n);
      m.erase(m.find(n));
    }
    return ret;
  }
};
