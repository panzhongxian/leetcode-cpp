#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    vector<string> num_strs(nums.size());
    for (int i = 0; i < nums.size(); i++) {
      num_strs[i] = std::to_string(nums[i]);
    }
    sort(num_strs.begin(), num_strs.end(),
         [](string& a, string& b) { return (a + b) > (b + a); });
    string ret;
    for (auto& s : num_strs) {
      ret += s;
    }
    if (ret[0] == '0') {
      return "0";
    }
    return ret;
  }
};
