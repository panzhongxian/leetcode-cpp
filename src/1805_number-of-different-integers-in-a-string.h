class Solution {
public:
  string lstrip_zero(const string &s) {
    int i = 0;
    while (i < s.size() && s[i] == '0') {
      i++;
    }
    return i == s.size() ? "0" : s.substr(i);
  }

  int numDifferentIntegers(string word) {
    size_t pos = 0;
    size_t end_pos;

    set<string> num_set;
    while (true) {
      pos = word.find_first_of("0123456789", pos);
      if (pos == string::npos) {
        return num_set.size();
      }

      end_pos = word.find_first_not_of("0123456789", pos);
      if (end_pos == string::npos) {
        num_set.insert(lstrip_zero(word.substr(pos)));
        return num_set.size();
      }
      num_set.insert(lstrip_zero(word.substr(pos, end_pos - pos)));
      pos = end_pos;
    }
    return num_set.size();
  }
};
