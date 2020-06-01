#include "base.h"
class Solution {
 public:
  int numDecodings(string s) {
    if (s.size() == 0) {
      return 0;
    }

    reverse(s.begin(), s.end());
    vector<int> nums(s.size() + 1, 0);
    nums[0] = 1;
    nums[1] = s[0] == '0' ? 0 : 1;
    for (size_t i = 1; i < s.size(); ++i) {
      int j = i + 1;
      int t1 = s[i] - '0';
      int t2 = s[i - 1] - '0';

      if (t1 == 0) {
        if (t2 == 0) {
          return 0;  // 00 is impossible
        }
        nums[j] = 0;
      } else if ((t1 * 10 + t2) > 26) {
        nums[j] = nums[j - 1];
      } else if (t2 == 0) {
        nums[j] = nums[j - 2];
      } else {
        nums[j] = nums[j - 1] + nums[j - 2];
      }
    }
    return nums.back();
  }
};
