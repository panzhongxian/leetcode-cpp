#include <algorithm>
#include <string>
using std::string;
using std::swap;
class Solution {
 public:
  bool is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
  }

  string reverseOnlyLetters(string S) {
    if (S.empty()) return S;

    int left = 0;
    int right = S.size() - 1;
    while (left < right) {
      if (!is_letter(S[left])) {
        left++;
      } else if (!is_letter(S[right])) {
        right--;
      } else {
        swap(S[left++], S[right--]);
      }
    }
    return S;
  }
};
