#include <map>
#include <string>

using std::map;
using std::string;

class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) {
      return false;
    }

    map<char, char> m1, m2;

#define x(i) (s[i] - 'a')
#define y(i) (t[i] - 'a')
    for (int i = 0; i < s.length(); i++) {
      if (m1.find(x(i)) == m1.end() && m2.find(y(i)) == m2.end()) {
        m1[x(i)] = y(i);
        m2[y(i)] = x(i);
      } else if (m1[x(i)] == y(i) && m2[y(i)] == x(i)) {
        continue;
      } else {
        return false;
      }
    }
    return true;
  }
};
