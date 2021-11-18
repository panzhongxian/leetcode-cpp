class Solution {
 public:
  void insert_words(string s) {
    while (!s.empty()) {
      string::size_type p1, p2;
      p1 = s.find_first_not_of(' ');
      if (p1 == string::npos) {
        break;
      }
      p2 = s.find(' ', p1);
      string word;
      if (p2 == string::npos) {
        word = s;
        s = "";
      } else {
        word = s.substr(p1, p2 - p1);
        s = s.substr(p2 + 1);
      }
      if (m.find(word) == m.end()) {
        m[word] = 0;
      }
      m[word]++;
    }
  }
  vector<string> uncommonFromSentences(string s1, string s2) {
    m.clear();
    insert_words(s1);
    insert_words(s2);
    vector<string> ret;
    for (auto &kv : m) {
      if (kv.second == 1) {
        ret.push_back(kv.first);
      }
    }
    return ret;
  }

 private:
  unordered_map<string, int> m;
};
