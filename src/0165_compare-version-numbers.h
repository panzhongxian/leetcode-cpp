#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  vector<int> VersionValue(string v) {
    int p0 = 0;
    vector<int> ret;
    auto pos = v.find('.', p0);
    while (pos != string::npos) {
      ret.push_back(atoi(v.substr(p0, pos).c_str()));
      p0 = pos + 1;
      pos = v.find('.', p0);
    }
    ret.push_back(atoi(v.substr(p0).c_str()));
    while (!ret.empty() && ret.back() == 0) {
      ret.pop_back();
    }
    return ret;
  }
  int compareVersion(string version1, string version2) {
    vector<int> v1, v2;
    v1 = VersionValue(version1);
    v2 = VersionValue(version2);
    auto it1 = v1.begin();
    auto it2 = v2.begin();
    while (it1 != v1.end() && it2 != v2.end()) {
      if (*it1 == *it2) {
        it1++;
        it2++;
        continue;
      }
      return (*it1 < *it2) ? -1 : 1;
    }
    if (it1 == v1.end() && it2 == v2.end()) {
      return 0;
    }
    return it1 == v1.end() ? -1 : 1;
  }
};
