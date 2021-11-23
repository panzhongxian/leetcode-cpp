class Solution {
public:
  bool check_is_palindrome(const string &s, int &l, int &r) {
    bool is_palindrome = true;
    while (l < r) {
      if (s[l] != s[r]) {
        is_palindrome = false;
        break;
      }
      l++;
      r--;
    }
    return is_palindrome;
  }

  bool validPalindrome(string s) {
    if (s.empty()) {
      return true;
    }

    int l = 0;
    int r = s.size() - 1;
    int skip_char_cnt = 0;
    if (check_is_palindrome(s, l, r)) {
      return true;
    }
    int ll = l;
    int rr = r;

    l = ll + 1;
    r = rr;
    if (check_is_palindrome(s, l, r)) {
      return true;
    }
    l = ll;
    r = rr - 1;
    if (check_is_palindrome(s, l, r)) {
      return true;
    }
    return false;
  }
};
