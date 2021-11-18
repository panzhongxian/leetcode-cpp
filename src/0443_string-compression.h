#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  int compress(vector<char>& chars) {
    if (chars.empty()) {
      return 0;
    }
    int cur_idx = 0;
    int cur_len = 1;
    char cur_char = chars[0];
    for (int i = 1; i < chars.size(); i++) {
      if (chars[i] == cur_char) {
        cur_len++;
        continue;
      }
      chars[cur_idx++] = cur_char;
      if (cur_len != 1) {
        for (char c : std::to_string(cur_len)) {
          chars[cur_idx++] = c;
        }
      }
      cur_char = chars[i];
      cur_len = 1;
    }
    chars[cur_idx++] = cur_char;
    if (cur_len != 1) {
      for (char c : std::to_string(cur_len)) {
        chars[cur_idx++] = c;
      }
    }
    return cur_idx;
  }
};
