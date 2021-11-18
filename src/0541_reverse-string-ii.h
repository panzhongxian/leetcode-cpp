class Solution {
 public:
  string reverseStr(string s, int k) {
    int word_start, word_end;
    word_start = 0;
    while (true) {
      if (auto try_end = word_start + k; try_end < s.size()) {
        word_end = try_end;
      } else {
        word_end = s.size();
      }
      reverse(s.begin() + word_start, s.begin() + word_end);

      word_start += 2 * k;
      if (word_start >= s.size()) {
        break;
      }
    }
    return s;
  }
};
