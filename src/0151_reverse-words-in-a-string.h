#include <stack>
#include <string>

using std::stack;
using std::string;

class Solution {
 public:
  string reverseWords(string s) {
    string::size_type p1;
    string::size_type p2 = 0;
    stack<string> words;
    while (true) {
      p1 = s.find_first_not_of(' ', p2);
      if (p1 == string::npos) {
        break;
      }
      p2 = s.find(' ', p1);
      if (p2 == string::npos) {
        words.push(s.substr(p1));
        break;
      } else {
        words.push(s.substr(p1, p2 - p1));
      }
    }
    string ret;
    while (words.size() > 1) {
      ret += words.top() + " ";
      words.pop();
    }
    ret += words.top();
    words.pop();
    return ret;
  }
};
