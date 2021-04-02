class Solution {
 public:
  bool hasGroupsSizeX(vector<int>& deck) {
    unordered_map<int, int> int_count_map;
    for (int i : deck) {
      if (int_count_map.find(i) == int_count_map.end()) {
        int_count_map[i] = 0;
      }
      int_count_map[i]++;
    }
    int min_count = deck.size();
    for (auto t : int_count_map) {
      if (t.second < min_count) {
        min_count = t.second;
      }
    }

    for (int i = 2; i < X; ++i) {
      bool divided_flag = true;
      for (auto t : int_count_map) {
        if (t.second % i) {
          divided_flag = false;
          break;
        }
      }
      if (divided_flag) {
        return true;
      }
    }
    return false;
  }
};
