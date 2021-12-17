class Solution {
 public:
  int minimumMoves(string s) {
    int ret = 0;
    auto pos = s.find('X');
    while (pos != string::npos) {
      ret++;
      pos += 3;
      if (pos >= s.size()) {
        return ret;
      }
      pos = s.find('X', pos);
    }
    return ret;
  }
};
