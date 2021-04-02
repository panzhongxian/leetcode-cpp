class Solution {
 public:
  bool rotateString(string A, string B) {
    if (A.size() != B.size()) {
      return false;
    }
    if (A.empty() && B.empty()) {
      return true;
    }
    int str_len = A.size();
    for (int i = 0; i < str_len; ++i) {
      bool match_flag = true;
      for (int j = 0; j < str_len; ++j) {
        if (B[(j + i) % str_len] != A[j]) {
          match_flag = false;
          break;
        }
      }
      if (match_flag) {
        return true;
      }
    }
    return false;
  }
};
