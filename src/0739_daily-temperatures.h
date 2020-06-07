#include "base.h"

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> ret(T.size());
    if (T.size() == 0) {
      return ret;
    }

    map<int, int> recent_temp_index;
    for (int i = T.size() - 1; i >= 0; --i) {
      recent_temp_index[T[i]] = i;
      auto it = next(recent_temp_index.find(T[i]));
      ret[i] = 0;
      while (it != recent_temp_index.end()) {
        if (ret[i] == 0 || ret[i] > (it->second - i)) {
          ret[i] = it->second - i;
        }
        it++;
      }
    }
    return ret;
  }
};

class Solution2 {
 public:
  vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> ret(T.size());
    stack<pair<int, int>> s;
    for (int i = T.size() - 1; i >= 0; --i) {
      while (!s.empty() && s.top().first <= T[i]) {
        s.pop();
      }

      ret[i] = s.empty() ? 0 : s.top().second;
      s.push({T[i], i});
    }
  }
};
