#include "base.h"
class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    int ret = 0;
    if (text1.length() == 0 || text2.length() == 0) {
      return ret;
    }

    vector<vector<int>> f(text1.size(), vector<int>(text2.size(), 0));
    for (size_t i = 0; i < f.size(); ++i) {
      for (size_t j = 0; j < f[0].size(); ++j) {
        if (i == 0 && j == 0) {
          f[i][j] = text1[i] == text2[j];
        } else if (i == 0) {
          f[i][j] = (text1[i] == text2[j]) ? 1 : f[i][j - 1];
        } else if (j == 0) {
          f[i][j] = (text1[i] == text2[j]) ? 1 : f[i - 1][j];
        } else {
          f[i][j] = max(f[i - 1][j], f[i][j - 1]);
          if (text1[i] == text2[j]) {
            f[i][j] = max(f[i - 1][j - 1] + 1, f[i][j]);
          }
        }
        if (ret < f[i][j]) {
          ret = f[i][j];
        }
      }
    }
    return ret;
  }
};
