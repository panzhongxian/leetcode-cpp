class Solution {
 public:
  double trimMean(vector<int>& arr) {
    map<int, int> m;
    double ret = 0;
    int cnt = 0;
    for (int i : arr) {
      ret += i;
      m[i]++;
      cnt++;
    }

    for (int i = 0; i < arr.size() / 20; i++) {
      ret -= m.begin()->first;
      cnt--;
      if (--m.begin()->second == 0) {
        m.erase(m.begin());
      }
    }

    for (int i = 0; i < arr.size() / 20; i++) {
      auto it = prev(m.end());
      ret -= it->first;
      cnt--;
      if (--(it->second) == 0) {
        m.erase(it);
      }
    }

    ret /= cnt;
    return ret;
  }
};
