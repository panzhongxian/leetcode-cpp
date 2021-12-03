class Solution {
public:
  int maxPower(string s) {
    int ret = 1;
    int curr_len = -1;
    char curr_char = '#';
    s.push_back('#');
    for (char c : s) {
      if (c != curr_char) {
        if (curr_len > ret) {
          ret = curr_len;
        }
        curr_char = c;
        curr_len = 1;
      } else {
        curr_len++;
      }
    }
    return ret;
  }
};
