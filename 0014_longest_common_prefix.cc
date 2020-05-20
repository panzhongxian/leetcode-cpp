#include "base.h"
class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0) {
      return "";
    }

    size_t max_comm_len = strs[0].size();
    for (auto s : strs) {
      if (max_comm_len > s.size()) {
        max_comm_len = s.size();
      }
    }

    for (size_t i = 1; i < strs.size() && max_comm_len > 0; ++i) {
      size_t j = 0;
      while (j <= max_comm_len) {
        if (strs[i][j] != strs[0][j]) {
          max_comm_len = j;
          break;
        }
        j++;
      }
    }
    return strs[0].substr(0, max_comm_len);
  }
};

TEST(S, Demo) { Solution s; }
