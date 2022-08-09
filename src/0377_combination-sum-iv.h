#include <vector>
using namespace std;

class Solution {
 public:
  int combinationSum4(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<int64_t> v(target + 1, 0);
    v[0] = 1;
    for (int i = 1; i < v.size(); i++) {
      int ret = 0;
      for (int num : nums) {
        if (num > i) {
          break;
        }
        ret += v[i - num];
      }
      v[i] = ret;
    }
    return v.back();
  }
};
