#include <map>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> numberOfPairs(vector<int>& nums) {
    map<int, int> m;
    for (int num : nums) {
      m[num]++;
    }
    int i = 0;
    int j = 0;
    for (auto [k, v] : m) {
      i += (v >> 1);
      j += v & 1;
    }
    return {i, j};
  }
};
