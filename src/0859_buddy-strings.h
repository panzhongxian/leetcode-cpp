#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  bool buddyStrings(string s, string goal) {
    vector<int> diff_pos;
    int s_char_count[26] = {0};

    if (s.size() != goal.size()) {
      return false;
    }

    for (int i = 0; i < s.size(); i++) {
      s_char_count[s[i] - 'a']++;
      if (s[i] == goal[i]) {
        continue;
      }
      diff_pos.push_back(i);
      if (diff_pos.size() > 2) {
        return false;
      }
    }

    if (diff_pos.size() == 2) {
      return s[diff_pos[0]] == goal[diff_pos[1]] &&
             s[diff_pos[1]] == goal[diff_pos[0]];
    }
    if (diff_pos.size() == 0) {
      for (int i = 0; i < 26; i++) {
        if (s_char_count[i] > 1) {
          return true;
        }
      }
    }
    return false;
  }
};
