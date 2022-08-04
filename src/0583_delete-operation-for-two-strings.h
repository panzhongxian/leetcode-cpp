#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int minDistance(string word1, string word2) {
    int ret = 0;
    unordered_map<int, int> min_len_start{{0, -1}};
    unordered_map<int, int> to_insert;
    for (int i = 0; i < word1.size(); i++) {
      size_t pos;
      for (auto [old_len, end_pos] : min_len_start) {
        pos = word2.find(word1[i], end_pos + 1);
        if (pos == string::npos) {
          continue;
        }
        int new_len = old_len + 1;
        if (ret < new_len) {
          ret = new_len;
        }
        if (min_len_start.find(new_len) == min_len_start.end() ||
            min_len_start[new_len] > pos) {
          if (to_insert.find(new_len) == to_insert.end() ||
              to_insert[new_len] > pos) {
            to_insert[new_len] = pos;
          }
        }
        /*
if (min_len_start.find(new_len) == min_len_start.end()) {
  cout << "??1" << new_len << "#" << pos << endl;
  to_insert.push_back({new_len, pos});
} else if (min_len_start[new_len] > pos) {
  cout << "??2" << new_len << "#" << pos << endl;
  // ERROR: 会影响到后续遍历到值
  // min_len_start[new_len] = pos;
}
        */
      }

      auto it = to_insert.begin();
      while (it != to_insert.end()) {
        min_len_start[it->first] = it->second;
        it = to_insert.erase(it);
      }
    }

    return word1.size() + word2.size() - ret - ret;
  }
};
