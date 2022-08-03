#include <stack>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> s;

    for (int i = nums.size() - 1; i >= 0; i--) {
      int n = nums[i];
      if (s.empty() || s.top() > n) {
        s.push(n);
        continue;
      }
      while (!s.empty() && s.top() <= n) {
        s.pop();
      }
      s.push(n);
    }

    vector<int> ret(nums.size());
    for (int i = ret.size() - 1; i >= 0; i--) {
      int n = nums[i];
      while (!s.empty() && s.top() <= n) {
        s.pop();
      }
      if (s.empty()) {
        ret[i] = -1;
      } else {
        ret[i] = s.top();
      }
      s.push(n);
    }
    return ret;
  }
};
