class Solution {
  vector<int> square_list;
  unordered_map<int, int> square_map;

public:
  Solution() { square_list = calc_square_list(); }
  vector<int> calc_square_list() {
    vector<int> square_list(251);
    for (int i = 0; i <= 250; i++) {
      square_list[i] = i * i;
      square_map[square_list[i]] = i;
    }
    return square_list;
  }

  int countTriples(int n) {
    int ret = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (auto kv = square_map.find(square_list[i] + square_list[j]);
            kv != square_map.end() && kv->second <= n) {
          ret++;
        }
      }
    }
    return ret;
  }
};
