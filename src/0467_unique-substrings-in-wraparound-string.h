#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
 public:
  int findSubstringInWraproundString(string p) {
    if (p.empty()) return 0;
    int max_end_substr_len[26] = {0};
    vector<int> end_substr_len(p.size(), 0);
    end_substr_len[0] = 1;
    max_end_substr_len[p[0] - 'a'] = 1;

    for (int i = 1; i < p.size(); i++) {
      if (p[i] - 'a' == (p[i - 1] - 'a' + 1) % 26) {
        end_substr_len[i] = end_substr_len[i - 1] + 1;
      } else {
        end_substr_len[i] = 1;
      }
      if (max_end_substr_len[p[i] - 'a'] < end_substr_len[i]) {
        max_end_substr_len[p[i] - 'a'] = end_substr_len[i];
      }
    }
    int ret = 0;
    for (int i = 0; i < 26; i++) {
      ret += max_end_substr_len[i];
    }
    return ret;
  }
};
