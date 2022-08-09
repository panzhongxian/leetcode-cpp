#include <vector>
using namespace std;
class Solution {
 public:
  int totalHammingDistance(vector<int>& nums) {
    int ret = 0;
    for (int num : nums) {
      ret |= num;
    }
    int bit_count = 0;
    while (ret) {
      bit_count++;
      ret >>= 1;
    }

    ret = 0;
    for (int i = 0; i < bit_count; i++) {
      int c0 = 0;
      int c1 = 0;
      int mask = 1 << i;
      for (int num : nums) {
        if (num & mask) {
          c1++;
        } else {
          c0++;
        }
      }
      ret += c0 * c1;
    }
    return ret;
  }
};
