class Solution {
 public:
  vector<int> constructRectangle(int area) {
    int l = floor(sqrt(area));
    while (true) {
      if (area % l == 0) {
        return vector<int>{max(l, area / l), min(l, area / l)};
      }
      l++;
    }
    return vector<int>{area, 1};
  }
};
