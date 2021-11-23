class Solution {
public:
  static bool check_repeate(string &str, int n) {
    if (str.size() % n != 0) {
      return false;
    }
    string needle = str.substr(0, n);

    for (int i = n; i < str.size(); i += n) {
      if (str.substr(i, n) != needle) {
        return false;
      }
    }
    return true;
  }
  string gcdOfStrings(string str1, string str2) {
    int n;
    if (str1.size() == str2.size()) {
      n = str1.size();
    } else if (str1.size() > str2.size()) {
      n = str1.size() - str2.size();
    } else {
      n = str2.size() - str1.size();
    }

    string ret;

    for (int i = n; i > 0; i--) {
      if (n % i != 0) {
        continue;
      }
      if (str1.substr(0, i) == str2.substr(0, i) && check_repeate(str1, i) &&
          check_repeate(str2, i)) {
        return str1.substr(0, i);
      }
    }
    return ret;
  }
};
