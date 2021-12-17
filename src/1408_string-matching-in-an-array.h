class Solution {
 public:
  vector<string> stringMatching(vector<string>& words) {
    vector<string> ret;
    if (words.empty()) {
      return ret;
    }
    sort(words.begin(), words.end(), [](const string& s1, const string& s2) {
      return s1.size() < s2.size();
    });
    for (int i = 0; i < words.size() - 1; i++) {
      for (int j = words.size() - 1; j > i; j--) {
        if (words[j].find(words[i]) != string::npos) {
          ret.push_back(words[i]);
          break;
        }
      }
    }
    return ret;
  }
};
