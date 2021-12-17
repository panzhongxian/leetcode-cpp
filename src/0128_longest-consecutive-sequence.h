#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s;
    for (int i : nums) {
      s.insert(i);
    }
    int ret = 0;
    for (int i : nums) {
      if (s.find(i - 1) == s.end()) {
        int j = i;
        while (s.find(j + 1) != s.end()) {
          j++;
        }
        if (j - i + 1 > ret) {
          ret = j - i + 1;
        }
      }
    }
    return ret;
  }
};