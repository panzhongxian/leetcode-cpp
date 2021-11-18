#include <string>

using std::string;

class Solution {
 public:
  int repeatedStringMatch(string a, string b) {
    if (b.empty()) {
      return 0;
    }
    if (a.empty()) {
      return -1;
    }

    if (a.find(b) != string::npos) {
      return 1;
    }
    if ((a + a).find(b) != string::npos) {
      return 2;
    }

    auto pos = b.find(a);
    if (pos >= a.size()) {
      return -1;
    }

    int ret = 0;
    if (pos != 0) {
      if (a.compare(a.size() - pos, pos, b.substr(0, pos)) != 0) {
        return -1;
      }
      ret = 1;
      b.erase(0, pos);
    }

    while (!b.empty()) {
      b = b.substr(a.size());
      ret += 1;
      if (b.size() < a.size()) {
        break;
      }
      if (b.compare(0, a.size(), a) != 0) {
        return -1;
      }
    }

    if (b.empty()) {
      return ret;
    }

    if (a.compare(0, b.size(), b) == 0) {
      return ret + 1;
    }
    return -1;
  }
};
