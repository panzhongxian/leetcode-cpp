#include <vector>
using std::vector;
class Solution {
 public:
  int findMinFibonacciNumbers(int k) {
    vector<int> fb_seq{1, 1};
    while (fb_seq.back() < k) {
      fb_seq.push_back(fb_seq[fb_seq.size() - 1] + fb_seq[fb_seq.size() - 2]);
    }
    int ret = 0;
    while (k) {
      auto it = lower_bound(fb_seq.begin() + 1, fb_seq.end(), k);
      if (*it > k) {
        it--;
      }
      k -= *it;
      ret++;
    }
    return ret;
  }
};
