class Solution {
 public:
  int maxDistance(vector<int> &colors) {
    map<int, pair<int, int>> m;
    for (int i = 0; i < colors.size(); i++) {
      int color = colors[i];
      if (m.find(color) == m.end()) {
        m[color] = pair<int, int>{i, i};
      } else {
        m[color].second = i;
      }
    }
    vector<pair<int, int>> vp;
    for (auto kv : m) {
      vp.push_back(move(kv.second));
    }
    int ret = 0;
    for (int i = 0; i < vp.size() - 1; i++) {
      for (int j = i + 1; j < vp.size(); j++) {
        int d1 = vp[i].second - vp[j].first;
        int d2 = vp[j].second - vp[i].first;
        ret = max(ret, max(d1, d2));
      }
    }
    return ret;
  }
};
