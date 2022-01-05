#include "base.h"
class Solution {
  static int m[26];
  static bool init_flag;

 public:
  Solution() {
    if (!init_flag) {
      InitDict();
      init_flag = true;
    }
  }
  bool checkWord(const string& word) {
    int prev_line = -1;
    for (char c : word) {
      int diff;
      if (c >= 'A' && c <= 'Z') {
        diff = c - 'A';
      } else {
        diff = c - 'a';
      }

      if (m[diff] != prev_line) {
        if (prev_line == -1) {
          prev_line = m[diff];
        } else {
          return false;
        }
      }
    }
    return true;
  }
  vector<string> findWords(vector<string>& words) {
    vector<string> ret;
    for (auto& word : words) {
      if (checkWord(word)) {
        ret.push_back(word);
      }
    }
    return ret;
  }
  static void InitDict() {
    string s1{"qwertyuiop"};
    for (char c : s1) {
      m[c - 'a'] = 1;
    }
    string s2{"asdfghjkl"};
    for (char c : s2) {
      m[c - 'a'] = 2;
    }
    string s3{"zxcvbnm"};
    for (char c : s3) {
      m[c - 'a'] = 3;
    }
  }
};

bool Solution::init_flag = false;
int Solution::m[26] = {};
