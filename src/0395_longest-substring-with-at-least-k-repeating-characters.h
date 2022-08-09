class Solution {
 public:
  int longestSubstring(string s, int k) {
    if (k > s.size()) {
      return 0;
    }
    int count[128] = {0};
    for (char c : s) {
      count[c]++;
    }
    int min_count = s.size();
    char min_char;
    int max_count = 0;
    for (int c = 'a'; c <= 'z'; c++) {
      if (count[c] > 0 && count[c] < min_count) {
        min_char = c;
        min_count = count[c];
      }
      if (count[c] > max_count) {
        max_count = count[c];
      }
    }
    if (max_count < k) {
      return 0;
    }
    if (min_count >= k) {
      return s.size();
    }
    int ret = 0;
    s.push_back(min_char);
    size_t pos = s.find_first_not_of(min_char, 0);
    while (pos != string::npos) {
      size_t end = s.find(min_char, pos);
      ret = max(longestSubstring(s.substr(pos, end - pos), k), ret);
      pos = s.find_first_not_of(min_char, end);
    }
    return ret;
  }
};
