#include <string>
#include <unordered_map>
using namespace std;
class Solution {
 public:
  int minNumberOfFrogs(string croakOfFrogs) {
    unordered_map<char, int> frogs;
    string what{"croak"};
    for (char c : what) {
      frogs[c] = 0;
    }
    for (char c : croakOfFrogs) {
      switch (c) {
        case 'c':
          if (frogs['k'] > 0) {
            frogs['k']--;
          }
          frogs['c']++;
          break;
#define kk(c1, c0)        \
  case c1:                \
    if (frogs[c0] == 0) { \
      return -1;          \
    } else {              \
      frogs[c0]--;        \
      frogs[c1]++;        \
    }                     \
    break;
          kk('r', 'c');
          kk('o', 'r');
          kk('a', 'o');
          kk('k', 'a');
      }
    }

    if (frogs['c'] || frogs['r'] || frogs['o'] || frogs['a']) {
      return -1;
    }
    return frogs['k'];
  }
};
