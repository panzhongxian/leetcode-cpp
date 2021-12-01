class Solution {
public:
  string kthDistinct(vector<string> &arr, int k) {
    unordered_map<string, int> m;
    vector<string> v;
    int i = 0;
    int cnt = 0;
    for (; i < arr.size(); i++) {
      auto &s = arr[i];
      if (m.find(s) == m.end()) {
        v.push_back(s);
        m[s] = cnt++;
      } else if (m[s] != -1) {
        v[m[s]] = "";
        m[s] = -1;
      }
    }

    i = 0;
    cnt = 0;
    for (; i < v.size(); i++) {
      if (!v[i].empty()) {
        cnt++;
        if (cnt == k) {
          return v[i];
        }
      }
    }
    return "";
  }
};
