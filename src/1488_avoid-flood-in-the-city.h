#include <list>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  int CheckAndDry(list<int>& zero_index_list, int last_index) {
    for (auto it = zero_index_list.begin(); it != zero_index_list.end(); it++) {
      if ((*it) > last_index) {
        int ret = *it;
        zero_index_list.erase(it);
        return ret;
      }
    }
    return -1;
  }
  vector<int> avoidFlood(const vector<int>& rains) {
    unordered_map<int, int> stat;
    vector<int> ret(rains.size(), -1);
    list<int> zero_index_list;

    for (int i = 0; i < rains.size(); i++) {
      int n = rains[i];
      if (n == 0) {
        zero_index_list.push_back(i);
      } else if (stat.find(n) == stat.end()) {
        stat[n] = i;
      } else if (zero_index_list.size() == 0) {
        return {};
      } else {
        int dried_index = CheckAndDry(zero_index_list, stat[n]);
        if (dried_index == -1) {
          return {};
        }
        ret[dried_index] = n;
        stat[n] = i;
      }
    }
    while (!zero_index_list.empty()) {
      ret[zero_index_list.front()] = 1;
      zero_index_list.pop_front();
    }
    return ret;
  }
};
