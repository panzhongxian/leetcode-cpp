class Solution {
 public:
  bool wordPattern(string pattern, string str) {
    map<char, string> m;
    for (char c : pattern) {
      if (str.empty()) {
        return false;
      }
      size_t pos = str.find(' ');
      string sub_str;
      if (pos == string::npos) {
        sub_str = str;
        str = "";
      } else {
        sub_str = str.substr(0, pos);
        str = str.substr(pos + 1);
      }
      cout << c << ": " << sub_str << endl;

      if (m.find(c) == m.end()) {
        m[c] = sub_str;
      } else if (m[c] != sub_str) {
        return false;
      }
    }

    if (!str.empty()) {
      return false;
    }
    set<string> s;
    for (auto x : m) {
      if (s.find(x.second) != s.end()) {
        return false;
      } else {
        s.insert(x.second);
      }
    }
    return true;
  }
};
