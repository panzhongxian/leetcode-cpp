#include <string>
using namespace std;
class Solution {
 public:
  string oneRound(const string& s, int k) {
    string ret;
    int i = 0;
    int sum = 0;
    for (char c : s) {
      sum += c - '0';
      i++;
      if (i % k == 0) {
        ret += to_string(sum);
        sum = 0;
      }
    }
    if (i % k) {
      ret += to_string(sum);
    }
    return ret;
  }
  string digitSum(string s, int k) {
    string t;
    while (s.size() > k) {
      t = oneRound(s, k);
      s = move(t);
    }
    return s;
  }
};
