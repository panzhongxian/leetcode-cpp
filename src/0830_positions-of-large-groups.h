class Solution {
 public:
  vector<vector<int>> largeGroupPositions(string s) {
    vector<vector<int>> ret;
    s.push_back('#');
    char curr_char = s[0];
    int curr_occur_cnt = 1;

    for (int i = 1; i < s.size(); i++) {
      if (curr_char == s[i]) {
        curr_occur_cnt++;
        continue;
      }
      if (curr_occur_cnt >= 3) {
        ret.push_back(vector<int>({i - curr_occur_cnt, i - 1}));
      }
      curr_char = s[i];
      curr_occur_cnt = 1;
    }
    return ret;
  }
};
