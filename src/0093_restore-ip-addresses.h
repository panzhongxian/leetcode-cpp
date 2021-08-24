#include <algorithm>
#include <string>
#include <vector>

using std::min;
using std::string;
using std::vector;

class Solution {
 public:
  bool is_ip_field(const string& s) {
    if (s.empty() || s.size() > 3) {
      return false;
    }
    if (s[0] == '0' && s.size() > 1) {
      return false;
    }
    int field_int = atoi(s.c_str());
    if (field_int > 255) {
      return false;
    }
    return true;
  }

  vector<string> splitStringArray(const string& s, int n) {
    if (n == 1) {
      if (!is_ip_field(s)) {
        return {};
      }
      return {s};
    }

    vector<string> ret;
    for (int i = 0;; i++) {
      string net_ip = s.substr(0, i + 1);
      if (net_ip.size() == i || !is_ip_field(net_ip)) {
        break;
      }
      auto sub_ip_array = splitStringArray(s.substr(i + 1), n - 1);
      for (auto& sub_ip : sub_ip_array) {
        sub_ip = net_ip + "." + sub_ip;
        ret.push_back(sub_ip);
      }
    }
    return ret;
  }
  vector<string> restoreIpAddresses(string s) {
    if (s.length() > 12) {
      return {};
    }
    return splitStringArray(s, 4);
  }
};
