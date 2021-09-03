#include <string>
using std::string;
class Solution {
 public:
  bool isValidSerialization(string preorder) {
    while (true) {
      auto p = preorder.find("#,#");
      if (p == 0) {
        return false;
      } else if (p == string::npos) {
        return preorder == "#";
      }

      auto tp = preorder.find_last_of(',', p - 2);
      if (tp == string::npos) {
        preorder[0] = '#';
        preorder.erase(1, p + 2);
      } else {
        preorder[tp + 1] = '#';
        preorder.erase(tp + 2, p - tp + 1);
      }
    }
  }
};
