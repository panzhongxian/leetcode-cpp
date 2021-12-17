class Solution {
public:
  string mostCommonWord(string paragraph, vector<string> &banned) {
    paragraph.push_back('.');
    unordered_set<string> banned_set;
    unordered_map<string, int> stat_map;
    for (const string &word : banned) {
      banned_set.insert(word);
    }
    int p1 = 0;
    for (int i = 0; i < paragraph.size(); i++) {
      char c = paragraph[i];
      if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        if (p1 == -1) {
          p1 = i;
        }
        continue;
      }
      if (p1 == -1) {
        continue;
      }

      string word = paragraph.substr(p1, i - p1);
      for (char &c : word) {
        if (c >= 'A' && c <= 'Z') {
          c = c - 'A' + 'a';
        }
      }
      p1 = -1;
      if (banned_set.find(word) != banned_set.end()) {
        continue;
      }
      stat_map[word]++;
    }
    string ret;
    int max_freq = INT_MIN;
    for (auto &[k, v] : stat_map) {
      if (v > max_freq) {
        max_freq = v;
        ret = k;
      }
    }
    return ret;
  }
};
