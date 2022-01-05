#include "base.h"

class Solution {
 public:
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    unordered_map<string, int> m;
    for (int i = 0; i < list1.size(); i++) {
      auto& restaurant = list1[i];
      m[restaurant] = -i - 1;
    }

    for (int i = 0; i < list2.size(); i++) {
      auto& restaurant = list2[i];
      if (m.find(restaurant) == m.end()) {
        m[restaurant] = -i - 1;
      } else {
        m[restaurant] = i + 1 - m[restaurant];
      }
    }

    int min_sum = INT_MAX;
    vector<string> ret;

    for (auto it = m.begin(); it != m.end(); it++) {
      if (it->second < 0) {
        continue;
      }
      if (it->second == min_sum) {
        ret.push_back(it->first);
      }
      if (it->second < min_sum) {
        min_sum = it->second;
        ret.clear();
        ret.push_back(it->first);
      }
    }
    return ret;
  }
};
