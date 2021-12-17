class Solution {
 public:
  int minTimeToType(string word) {
    int ret = word.size();
    char prev_char = 'a';
    int curr_diff;
    for (int i = 0; i < word.size(); i++) {
      curr_diff = abs(word[i] - prev_char);
      prev_char = word[i];
      ret += min(curr_diff, 26 - curr_diff);
    }
    return ret;
  }
};
