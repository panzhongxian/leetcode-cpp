class Solution {
 public:
  static int count_bit(int i) {
    auto ret = 0;
    while (i) {
      if (i & 1) {
        ret++;
      }
      i >>= 1;
    }
    return ret;
  }
  vector<int> sortByBits(vector<int>& arr) {
    map<int, vector<int>> m;
    for (int i : arr) {
      auto bit_cnt = count_bit(i);
      if (m.find(bit_cnt) == m.end()) {
        m[bit_cnt] = vector{i};
      } else {
        m[bit_cnt].push_back(i);
      }
    }
    vector<int> ret;
    for (auto& kv : m) {
      sort(kv.second.begin(), kv.second.end());
      ret.insert(ret.end(), make_move_iterator(kv.second.begin()),
                 make_move_iterator(kv.second.end()));
    }
    return ret;
  }
};
