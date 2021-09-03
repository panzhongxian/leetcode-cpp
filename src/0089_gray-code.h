#include <vector>
using std::vector;

class Solution {
 public:
  vector<int> grayCode(int n) {
    vector<int> ret(1 << n, 0);
    int factor = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < factor; j++) {
        ret[factor + j] = factor + ret[factor - j - 1];
      }
      factor <<= 1;
    }
    return ret;
  }
};
