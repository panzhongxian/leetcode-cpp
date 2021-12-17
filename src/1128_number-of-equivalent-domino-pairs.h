namespace std {
typedef pair<int, int> Domino;
template <>
struct hash<Domino> {
  std::size_t operator()(const Domino &k) const {
    using std::hash;
    return hash<int>()(k.first) ^ (hash<int>()(k.second) << 1);
  }
};
}  // namespace std

class Solution {
 public:
  int numEquivDominoPairs(vector<vector<int>> &dominoes) {
    unordered_map<pair<int, int>, int> m;
    for (auto &v : dominoes) {
      Domino d;
      if (v[0] > v[1]) {
        d.first = v[1];
        d.second = v[0];
      } else {
        d.first = v[0];
        d.second = v[1];
      }
      if (m.find(d) == m.end()) {
        m[d] = 1;
      } else {
        m[d]++;
      }
    }
    int ret = 0;
    for (auto &kv : m) {
      if (kv.second > 1) {
        ret += kv.second * (kv.second - 1) / 2;
      }
    }
    return ret;
  }
};
