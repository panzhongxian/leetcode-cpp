#include <string>
using namespace std;
class Solution {
 public:
  string reverseWords(string s) {
    size_t word_start = s.find_first_not_of(' ', 0);
    size_t word_end, non_char_pos;

    while (true) {
      non_char_pos = s.find_first_of(' ', word_start);
      if (non_char_pos == string::npos) {
        word_end = s.size() - 1;
      } else {
        word_end = non_char_pos - 1;
      }

      for (int i = 0; i < (word_end - word_start + 1) / 2; i++) {
        swap(s[word_start + i], s[word_end - i]);
      }
      if (non_char_pos == string::npos) {
        return s;
      } else {
        word_start = s.find_first_not_of(' ', non_char_pos);
      }
      if (word_start == string::npos) {
        return s;
      }
    }
    return s;
  }
};
