#include <iostream>
#include <string>

using std::string;

class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    int s1_len = s1.size();
    int s2_len = s2.size();
    int s3_len = s3.size();
    if (s1_len + s2_len != s3_len) {
      return false;
    }

    bool fnm[s1_len + 1][s2_len + 1];

    fnm[0][0] = true;
    for (int i = 1; i <= s1_len; i++) {
      fnm[i][0] = fnm[i - 1][0] && (s1[i - 1] == s3[i - 1]);
    }
    for (int j = 1; j <= s2_len; j++) {
      fnm[0][j] = fnm[0][j - 1] && (s2[j - 1] == s3[j - 1]);
    }
    for (int i = 1; i <= s1_len; i++) {
      for (int j = 1; j <= s2_len; j++) {
        fnm[i][j] = (fnm[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) ||
                    (fnm[i][j - 1] && (s2[j - 1] == s3[i + j - 1]));
      }
    }

    return fnm[s1_len][s2_len];
  }
};
