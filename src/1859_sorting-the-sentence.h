class Solution {
public:
  string sortSentence(string s) {
    vector<string> v(10);
    string ret;
    s.push_back(' ');
    size_t start = 0;
    auto end = s.find(' ');
    while (start < s.size()) {
      v[s[end - 1] - '1'] = s.substr(start, end - start - 1);
      start = end + 1;
      end = s.find(' ', start);
    }
    for (auto &word : v) {
      if (word.empty()) {
        break;
      }
      if (!ret.empty()) {
        ret.push_back(' ');
      }
      ret += word;
    }

    return ret;
  }
};
