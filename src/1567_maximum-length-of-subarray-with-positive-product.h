#include <vector>
using namespace std;
class Solution {
 public:
  int getMaxLen(vector<int>& nums) {
    int t1 = 0;  // positive count
    int t2 = 0;  // negative count
    int prev_t1, prev_t2;
    int ret = 0;

    for (int n : nums) {
      if (n == 0) {
        t1 = 0;
        t2 = 0;
        continue;
      } else if (n > 0) {
        t1++;
        if (t2 != 0) {
          t2++;
        }
      } else {
        int new_t2 = t1 + 1;
        int new_t1 = t2 ? t2 + 1 : 0;
        t2 = new_t2;
        t1 = new_t1;
      }
      ret = max(t1, ret);
    }
    return ret;
  }
};
