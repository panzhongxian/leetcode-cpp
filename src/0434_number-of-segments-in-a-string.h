class Solution {
 public:
  int countSegments(string s) {
    int ret = 0;
    string::size_type p1, p2;
    p2 = 0;
    while (true) {
      p1 = s.find_first_not_of(' ', p2);
      if (p1 == string::npos) {
        return ret;
      }
      p2 = s.find(' ', p1);
      if (p2 == string::npos) {
        return ret + 1;
      }
      p1 = p2;
      ret++;
    }
    return ret;
  }
};
