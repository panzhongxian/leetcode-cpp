#include "base.h"

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<string>> weight_str_dict;
    for (auto s : strs) {
      auto raw_s = s;
      sort(s.begin(), s.end());
      weight_str_dict[s].push_back(raw_s);
    }
    vector<vector<string>> ret;
    for (map<string, vector<string>>::iterator iter = weight_str_dict.begin();
         iter != weight_str_dict.end(); ++iter) {
      ret.push_back(move(iter->second));
    }
    return ret;
  }
};
