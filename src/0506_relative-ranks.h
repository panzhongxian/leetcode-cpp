class Solution {
 public:
  vector<string> findRelativeRanks(vector<int> &score) {
    vector<string> ret(score.size());
    map<int, int> m;
    for (int i = 0; i < score.size(); i++) {
      m[-score[i]] = i;
    }

    int i = 1;
    for (auto &kv : m) {
      switch (i) {
        case 1:
          ret[kv.second] = "Gold Medal";
          break;
        case 2:
          ret[kv.second] = "Silver Medal";
          break;
        case 3:
          ret[kv.second] = "Bronze Medal";
          break;
        default:
          ret[kv.second] = to_string(i);
      }
      i++;
    }
    return ret;
  }
};
