namespace std {
typedef pair<int, int> Domino;
template <>
struct hash<Domino> {
  std::size_t operator()(const Domino& k) const {
    using std::hash;
    return hash<int>()(k.first) ^ (hash<int>()(k.second) << 1);
  }
};
}  // namespace std
class Solution {
 public:
  bool isPathCrossing(string path) {
    pair<int, int> location{0, 0};
    unordered_set<pair<int, int>> s{location};
    for (char c : path) {
      switch (c) {
        case 'N':
          location.first++;
          break;
        case 'S':
          location.first--;
          break;
        case 'E':
          location.second++;
          break;
        case 'W':
          location.second--;
          break;
      }
      if (s.find(location) == s.end()) {
        s.insert(location);
      } else {
        return true;
      }
    }
    return false;
  }
};
