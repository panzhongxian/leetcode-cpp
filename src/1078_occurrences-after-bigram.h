class Solution {
public:
  vector<string> findOcurrences(string text, string first, string second) {
    text = " " + text;
    string needle = " " + first + " " + second + " ";
    size_t pos = 0;
    vector<string> ret;
    while (true) {
      pos = text.find(needle, pos);
      if (pos == string::npos) {
        break;
      }
      auto start_pos = pos + needle.length();
      auto end_pos = text.find(' ', start_pos);
      if (end_pos == string::npos) {
        ret.push_back(text.substr(start_pos));
      } else {
        ret.push_back(text.substr(start_pos, end_pos - start_pos));
      }
      pos += first.length() + 1;
    }
    return ret;
  }
};
