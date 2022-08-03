#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> triggers;
    for (char c : s1) {
      triggers[c]++;
    }
    int s1_len = s1.size();
    int checked_len = 0;
    for (int i = 0; i < s2.size();) {
      if (triggers.find(s2[i]) == triggers.end()) {
        i++;
        continue;
      }

      auto temp_triggers{triggers};
      checked_len = 0;
      while (i + checked_len < s2.size()) {
        char c = s2[i + checked_len];
        if (temp_triggers.find(c) != temp_triggers.end()) {
          temp_triggers[c]--;
          if (temp_triggers[c] == 0) {
            temp_triggers.erase(c);
          }
          checked_len++;
        } else if (triggers.find(c) == triggers.end()) {
          i = i + checked_len;
          break;
        } else if (s2[i] == c) {
          i++;
        } else if (checked_len > 0) {
          temp_triggers[s2[i]]++;
          checked_len--;
          i++;
        } else {
          i++;
          break;
        }
        if (checked_len == s1_len) {
          return true;
        }
        if (i + s1.size() > s2.size()) return false;
      }
    }
    return false;
  }
};
