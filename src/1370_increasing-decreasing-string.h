class Solution {
public:
  string sortString(string s) {
    list<pair<char, int>> l;
    int m[26];
    memset(m, 0, 26 * sizeof(int));
    for (char c : s) {
      m[c - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      if (m[i] != 0) {
        l.push_back(pair<char, int>(i + 'a', m[i]));
      }
    }
    string ret;
    while (!l.empty()) {
      for (auto it = l.begin(); it != l.end();) {
        ret.push_back(it->first);
        it->second--;
        if (it->second == 0) {
          it = l.erase(it);
        } else {
          it++;
        }
      }

      if (l.empty()) {
        break;
      }
      reverse(l.begin(), l.end());
    }
    return ret;
  }
};
