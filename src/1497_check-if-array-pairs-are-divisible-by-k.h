#include <vector>
using std::vector;
class Solution {
 public:
  bool canArrange(const vector<int>& arr, int k) {
    vector<int> stat(k + 1, 0);
    for (int n : arr) {
      if (n >= 0) {
        stat[n % k]++;
      } else {
        stat[((k - (-n % k)) % k)]++;
      }
    }
    if (stat[0] & 1) {
      return false;
    }
    if (((k & 1) == 0) && stat[k >> 1] & 1) {
      return false;
    }

    for (int i = 1; i <= (k >> 1); i++) {
      if (stat[i] != stat[k - i]) {
        return false;
      }
    }
    return true;
  }
};
