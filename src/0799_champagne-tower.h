class Solution {
 public:
  double champagneTower(int poured, int query_row, int query_glass) {
    vector<double> row(1, poured);

    for (int i = 0; i < query_row; i++) {
      vector<double> next_row(i + 2, 0.0);
      for (int j = 0; j < i + 1; j++) {
        if (row[j] > 1.0) {
          double t = (row[j] - 1.0) / 2.0;
          next_row[j] += t;
          next_row[j + 1] += t;
        }
      }
      row = std::move(next_row);
    }
    return min(row[query_glass], 1.0);
  }
};
