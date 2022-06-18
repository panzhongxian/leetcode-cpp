class Solution {
 public:
  int maximumSwap(int num) {
    if (num < 10) {
      return num;
    }

    vector<int> v;
    map<int, vector<int>> mv;
    for (int i = 0; num; i++) {
      v.push_back(num % 10);
      mv[v.back()].push_back(i);
      num /= 10;
    }
    for (int i = v.size() - 1; i >= 0; i--) {
      if (v[i] == mv.rbegin()->first) {
        mv.rbegin()->second.pop_back();
        if (mv.rbegin()->second.empty()) {
          mv.erase(v[i]);
        }
      } else {
        swap(v[i], v[mv.rbegin()->second[0]]);
        break;
      }
    }
    int ret = 0;
    for (int i = v.size() - 1; i >= 0; i--) {
      ret = ret * 10 + v[i];
    }

    return ret;
  }
};
