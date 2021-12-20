class Solution {
 public:
  int maxRepeating(string sequence, string word) {
    string needle;
    for (int i = 0; i < sequence.size() / word.size(); i++) {
      needle += word;
      if (sequence.find(needle) == string::npos) {
        return i;
      }
    }
    return sequence.size() / word.size();
  }
};
