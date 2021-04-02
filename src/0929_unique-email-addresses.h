#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  string RealEmail(const string& s) {
    // 0: start: filter out '.' ; transfer to 1 or 2;
    // 1: found '+' but not '@'
    // 2: find '@'
    string ret;
    int state = 0;
    for (char c : s) {
      if (state == 0) {
        if (c == '.') {
          // pass
        } else if (c == '+') {
          state = 1;
        } else if (c == '@') {
          state = 2;
          ret += c;
        } else {
          ret += c;
        }
      } else if (state == 1 && c == '@') {
        state = 2;
        ret += c;
      } else if (state == 2) {
        ret += c;
      }
    }
    return ret;
  }
  int numUniqueEmails(vector<string>& emails) {
    unordered_map<string, int> m;
    for (auto& email : emails) {
      m[RealEmail(email)]++;
    }
    return m.size();
  }
};
