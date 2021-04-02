#include <string>
#include <unordered_map>
#include <vector>

#include "base.h"
using namespace std;
class Solution {
 public:
  int uniqueMorseRepresentations(vector<string>& words) {
    unordered_map<string, int> dict;
    for (const auto& word : words) {
      string code;
      for (char c : word) {
        code += morse_map[c - 'a'];
      }
      dict[code] = 0;
    }
    return dict.size();
  }

 private:
  const vector<string> morse_map{
      ".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
      ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
      "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.."};
};
