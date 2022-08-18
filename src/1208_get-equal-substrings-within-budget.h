#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  int equalSubstring(string s, string t, int maxCost) {
    vector<int> v(s.size());
    for (int i = 0; i < s.size(); i++) {
      v[i] = abs(s[i] - t[i]);
    }

    int left = 0;
    int right = 0;
    while (right < s.size()) {
      if (v[right] <= maxCost) {
        maxCost -= v[right++];
      } else {
        maxCost -= v[right++];
        maxCost += v[left++];
      }
    }
    return right - left;
  }
};
