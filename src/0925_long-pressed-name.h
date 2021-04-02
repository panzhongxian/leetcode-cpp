#include <string>
using std::string;
class Solution {
 public:
  bool isLongPressedName(string name, string typed) {
    if (typed[0] != name[0]) {
      return false;
    }
    int i = 1;
    int j = 1;
    for (; i < name.size() || j < typed.size();) {
      if (name[i] == typed[j]) {
        i++;
        j++;
      } else if (typed[j] == typed[j - 1]) {
        j++;
      } else {
        return false;
      }
    }
    return true;
  }
};
