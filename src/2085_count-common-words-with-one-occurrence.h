class Solution {
 public:
  int countWords(vector<string>& words1, vector<string>& words2) {
    unordered_map<string, int> m1, m2;
    for (auto& word : words1) {
      m1[word]++;
    }
    for (auto& word : words2) {
      m2[word]++;
    }
    int ret = 0;
    for (auto& kv : m1) {
      if (kv.second > 1) {
        continue;
      }
      if (m2.find(kv.first) != m2.end() && m2[kv.first] == 1) {
        ret++;
      }
    }
    return ret;
  }
};
