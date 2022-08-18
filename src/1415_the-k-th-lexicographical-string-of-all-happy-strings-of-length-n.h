#include <map>
#include <string>
using namespace std;
class Solution {
 public:
  char getCharOnBase(int n, int base, char prev) {
    const map<char, string> m{{'a', "bc"}, {'b', "ac"}, {'c', "ab"}};
    const string& s = m.at(prev);
    return n < base ? s[0] : s[1];
  }
  string getHappyString(int n, int k) {
    int base = 1 << (n - 1);
    if (k > 3 * base) {
      return "";
    }

    char first_char = 'a' + (k - 1) / base;
    string ret;
    ret.push_back(first_char);
    k = (k - 1) % base;
    base >>= 1;
    while (base) {
      ret.push_back(getCharOnBase(k, base, ret.back()));
      k = k % base;
      base >>= 1;
    }

    return ret;
  }
};
