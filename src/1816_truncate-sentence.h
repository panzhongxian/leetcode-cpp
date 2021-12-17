class Solution {
 public:
  string truncateSentence(string s, int k) {
    size_t pos = 0;
    size_t end_pos = string::npos;

    for (int words = 0; words < k; words++) {
      pos = s.find(' ', pos);
      if (pos == string::npos) {
        return s;
      }
      pos += 1;
    }
    return s.substr(0, pos - 1);
  }
};
