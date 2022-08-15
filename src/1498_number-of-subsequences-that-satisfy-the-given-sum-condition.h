#include <algorithm>
#include <vector>
using namespace std;

constexpr int mod_base = 1000000007;

class Solution {
 public:
  int numSubseq(vector<int>& nums, int target) {
    vector<int> moddeds(nums.size() + 1);
    moddeds[0] = 1;
    int last_modded_index = 0;
    auto get_modded = [&](int k) {
      while (last_modded_index <= k) {
        last_modded_index++;
        moddeds[last_modded_index] = moddeds[last_modded_index - 1] << 1;
        moddeds[last_modded_index] %= mod_base;
      }
      return moddeds[k];
    };

    sort(nums.begin(), nums.end());

    int ret = 0;
    auto right_it = nums.end();
    auto left_it = nums.begin();
    while (left_it <= right_it) {
      right_it = upper_bound(left_it, right_it, target - *left_it);
      int k = distance(left_it, right_it) - 1;
      if (k > 0 || (k == 0 && ((*left_it) << 1) <= target)) {
        ret = (ret + get_modded(k)) % mod_base;
        left_it++;
      } else {
        break;
      }
    }

    return ret;
  }
};
