#include <map>
#include <vector>

using std::map;
using std::multimap;
using std::pair;
using std::vector;

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> num_count;
    for (int i : nums) {
      if (num_count.find(i) == num_count.end()) {
        num_count[i] = 0;
      }
      num_count[i] += 1;
    }

    multimap<int, int> count_num;
    for (auto& kv : num_count) {
      count_num.insert({kv.second, kv.first});
    }

    vector<int> ret;
    auto it = count_num.rbegin();
    for (int i = 0; i < k; i++) {
      ret.push_back(it->second);
      it++;
    }
    return ret;
  }
};
