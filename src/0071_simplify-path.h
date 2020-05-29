#include "base.h"

class Solution {
 public:
  string simplifyPath(string path) {
    vector<string> stack;
    size_t pos;
    string cur_dir;

    while (!path.empty()) {
      pos = path.find_first_of('/');
      if (pos == string::npos) {
        cur_dir = path;
        path = "";
      } else {
        cur_dir = path.substr(0, pos);
        path = path.substr(pos + 1);
      }

      if (cur_dir.empty() || cur_dir == ".") {
      } else if (cur_dir == "..") {
        if (stack.size()) {
          stack.pop_back();
        }
      } else {
        stack.push_back(cur_dir);
      }
    }
    string ret;

    for (auto cur_dir : stack) {
      ret += "/" + cur_dir;
    }
    if (ret.empty()) {
      ret = "/";
    }

    return ret;
  }
};
