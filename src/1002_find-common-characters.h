#include <cstring>
#include <string>
#include <vector>

using namespace std;
class Solution {
 public:
  vector<string> commonChars(vector<string>& A) {
    vector<string> ret;
    if (A.empty()) {
      return ret;
    }

    LoadToMap(A[0], inter_mp);
    for (size_t i = 1; i < A.size(); i++) {
      int tmp_map[26];
      LoadToMap(A[i], tmp_map);
      int total_cnt = 0;
      for (int j = 0; j < 26; j++) {
        if (tmp_map[j] < inter_mp[j]) {
          inter_mp[j] = tmp_map[j];
        }
        total_cnt += inter_mp[j];
      }
      if (total_cnt == 0) {
        return ret;
      }
    }

    for (int i = 0; i < 26; i++) {
      if (inter_mp[i] == 0) {
        continue;
      }
      ret.insert(ret.end(), inter_mp[i], string(1, (char)(i + 'a')));
    }
    return ret;
  }

 private:
  void LoadToMap(const string& s, int mp[]) {
    memset(mp, 0, sizeof(int) * 26);
    for (char c : s) {
      mp[c - 'a']++;
    }
  }
  int inter_mp[26];
};
