class Solution {
 public:
  int maxDepth(string s) {
    int ret = 0;
    int depth = 0;
    for (char c : s) {
      if (c == '(') {
        depth++;
        if (depth > ret) {
          ret = depth;
        }
      } else if (c == ')') {
        depth--;
      }
    }
    return ret;
  }
};
