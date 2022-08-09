#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
  unordered_map<string, int> bank_set;

 public:
  bool IsMutation(const string& s1, const string& s2) {
    int diff = 0;
    for (int i = 0; i < s1.size(); i++) {
      if (s1[i] != s2[i]) {
        diff++;
      }
    }
    return diff == 1;
  }

  int CheckTargetMinPath(const string& start, const string& end) {
    if (bank_set.find(end) == bank_set.end() || bank_set[end] == 0) {
      return -1;
    }

    if (IsMutation(start, end)) {
      return 1;
    }

    int ret = -1;
    int tmp_path_len;
    bank_set[end] = 0;
    for (auto [k, v] : bank_set) {
      if (v == 0) {
        continue;
      }
      if (IsMutation(k, end)) {
        tmp_path_len = CheckTargetMinPath(start, k);
        if (tmp_path_len == -1) {
          continue;
        }
        tmp_path_len += 1;
        if (ret == -1 || ret > tmp_path_len) {
          ret = tmp_path_len;
        }
      }
    }
    bank_set[end] = 1;
    return ret;
  }

  int minMutation(const string& start, const string& end,
                  const vector<string>& bank) {
    for (auto s : bank) {
      bank_set.insert({s, 1});
    }
    return CheckTargetMinPath(start, end);
  }
};
