class Solution {
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image) {
    for (auto &v : image) {
      reverse(v.begin(), v.end());
      for (int i = 0; i < v.size(); i++) {
        v[i] = v[i] ^ 1;
      }
    }
    return image;
  }
};
